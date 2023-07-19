#include <iostream>
#include <vector>
using namespace std;

    int solveMem(int n,vector<int> &dp){
        if(n==1)
            return 1;
        if(n==2)
            return 2;

        if(dp[n]!=-1)
            return dp[n];

        return dp[n] = solveMem(n-1,dp) + solveMem(n-2,dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solveMem(n,dp);
    }

    int main(){
        int n = 4;
        cout<<climbStairs(n);
        return 0;
    }