 #include <iostream>
 #include <unordered_map>
 #include <algorithm>
 using namespace std;

 
 int solve(int index, int A[], int difference,unordered_map<int,int> dp[]){
        if(index < 0)
                return 0;
        
        //Kya iss index pr koi ans exist krta hai, agar karta hai toh woh answer return kr do
        if(dp[index].count(difference))
            return dp[index][difference];
        
        int ans = 0;
        for(int j = index-1;j>=0;j--){
            if(A[index]-A[j]==difference)
                ans = max(ans, 1+solve(j,A,difference,dp));
        }
        
        dp[index][difference] = ans;
        return dp[index][difference];
    }
    
    int solveTab(int A[], int n){
        
        if(n<=2)
            return n;
        
        //Kyunki bhaii har baar, har index par difference change ho raha hai
        //aur har difference par length change ho rahi hai bc.
        unordered_map<int,int> dp[n+1];
        int ans = 0;
        
        for(int i = 1; i<n;i++){
            for(int j=0;j<i;j++){
                    int diff = A[i]-A[j];
                    int cnt = 1;
                    
                    if(dp[j].count(diff))
                        cnt =  dp[j][diff];
                    
                    //Storing answer     
                    dp[i][diff] = 1 + cnt;
                    ans = max({ans, dp[i][diff]});
            }
        }
        return ans;
    }

    int lengthOfLongestAP(int A[], int n) {
        // code here
        return solveTab(A,n);
    }

    int main(){
       const int N = 6;
        int set[N] = {1, 7, 10, 13, 14, 19};
        cout<<lengthOfLongestAP(set,N);
        return 0;
    }