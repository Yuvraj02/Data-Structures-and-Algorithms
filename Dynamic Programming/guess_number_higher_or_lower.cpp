#include <iostream>
#include <vector>

using namespace std;

 int solveRec(int start, int end){
        if(start >= end)
            return 0;

        int maxi = INT32_MAX;

        for(int i=start; i<=end;i++){
            maxi = min(maxi, i + max(solveRec(start,i-1), solveRec(i+1,end)));
        }
        return maxi;
    }

    int solveMem(int start, int end, vector<vector<int>> &dp){
        if(start>=end)
            return 0;

        if(dp[start][end]!=-1)
            return dp[start][end];
        
        int minAmount = INT32_MAX;

        for(int i = start; i<=end; i++){
            minAmount = min(minAmount, i + max(solveMem(start,i-1,dp), solveMem(i+1,end,dp)));
        }

        return dp[start][end] = minAmount;

    }

    int solveTab(int n){
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int start = n;start>=1;start--){
            for(int end = start; end<=n;end++){
                if(start==end)
                    continue;
                
            int minAmount = INT32_MAX;

            for(int i = start; i<=end; i++){
                minAmount = min(minAmount, i + max(dp[start][i-1], dp[i+1][end]));
            }
            dp[start][end] = minAmount;
            }
        }

        return dp[1][n];

    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));

       //return solveMem(1,n,dp);
        return solveTab(n);
    }


int main(){

    cout<<getMoneyAmount(10);

    return 0;
}