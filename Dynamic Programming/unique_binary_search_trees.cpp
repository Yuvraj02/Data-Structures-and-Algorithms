#include <iostream>
#include <vector>
using namespace std;

 int solve(int n){
        if(n<=1)
            return 1;
        
        int ans = 0;

        for(int i = 1; i<=n;i++){
            ans += solve(i-1)* solve(n-i);
        }

        return ans;
    }

    int solveMem(int n, vector<int> &dp){

        if(n<=1)
            return 1;

        if(dp[n]!=-1)
            return dp[n];

        int ans = 0;

        for(int i = 1; i<=n;i++){
            ans += solveMem(i-1,dp) * solveMem(n-i,dp);
        }

        return dp[n] = ans;
    }

    int solveTab(int n){

        vector<int> dp(n+1,1);

        for(int i = 2; i<=n;i++){
            int ans = 0;
                for(int j = 1; j<=i; j++){
                    ans += dp[j-1] * dp[i-j];
                }
            dp[i] = ans; 
        }
        return dp[n];
    }

int main(){ 

    int n = 3;

    //vector<int> dp(n+1,-1);
    //cout<<solveMem(n,dp);
    cout<<solveTab(n);
    return 0;
}

