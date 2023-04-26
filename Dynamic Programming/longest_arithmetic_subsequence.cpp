  #include <vector>
  #include <iostream>
  #include <unordered_map>

  using namespace std;
  
  int solve(int index, vector<int>& arr, int difference,vector<int>&dp){
        if(index < 0)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int ans = 0;
        for(int j = index-1;j>=0;j--){
            if(arr[index]-arr[j]==difference)
                ans = max(ans, 1 + solve(j,arr,difference,dp));
        }

        dp[index] = ans;
        return dp[index];
    }

    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        if(n<=2)
            return n;
        unordered_map<int,int> dp;
        int ans = 0;

        for(int i=0;i<n;i++){
            //Check if the current - difference is there in map or not
            int temp = arr[i] - difference;
            int tempAns = 0;
            
            if(dp.count(temp))
                tempAns = dp[temp]; //Store the temp value

            dp[arr[i]] = 1 + tempAns;

            ans = max(ans, dp[arr[i]]);
        }

        return ans;
    }

    int main(){

        vector<int> A = {1,2,3,4};
        int difference = 1;
        cout<<longestSubsequence(A,difference);
    }