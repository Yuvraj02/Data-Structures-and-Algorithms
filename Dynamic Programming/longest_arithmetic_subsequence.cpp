  #include <vector>
  #include <iostream>
  #include <unordered_map>

  using namespace std;
  //DP Solution
  int largestFrom(int i, vector<int> &arr, int diff,int n,vector<int> &dp){
        if(i>=n-1)
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        int ans = 0;
        for(int j = i+1; j < n;j++){
            if(arr[j]-arr[i]==diff)
                ans = max(ans,1 + largestFrom(j,arr,diff,n,dp));
        }

        return dp[i] = ans;
    }
//Tabulation 
    int larestFromTab(vector<int>& arr, int diff){
        int n =arr.size();

        vector<int> dp(n+1,0);
        int maxLength = 0;
        for(int i = 0; i<arr.size();i++){

            for(int j = n-2; j>=0;j--){
                int ans = 0;
                for(int k = j+1; k<n;k++){
                    if(arr[k]-arr[j]==diff)
                        ans = max(ans,1 + dp[k]);
                }
                dp[j] = ans;
            }
            maxLength = max(1+dp[i],maxLength);
        }
        return maxLength;
    }

//Space optimization
    int longestSubsequence(vector<int>& arr, int diff) {
        
        unordered_map<int,int> dp;
        int max_length = INT32_MIN;
        for(int i = 0; i<arr.size();i++){

            int val = arr[i] - diff;
            //If the value after subtracting difference already exists, then add + 1 to the length of prev existing val
            //to the current val
            dp[arr[i]] = 1 + dp[val];
            
            max_length = max(max_length,dp[arr[i]]);
        }
        return max_length;
    }

    int main(){

        vector<int> A = {1,2,3,4};
        int difference = 1;
        cout<<longestSubsequence(A,difference);
    }