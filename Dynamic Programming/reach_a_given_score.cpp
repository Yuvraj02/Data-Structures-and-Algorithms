#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int solve(int n, int selected){
    if(n==0)
        return 1;

    if(n<0)
        return 0;
    
    int a = 0,b=0,c=0;

    if(selected <=3)
        a  =  solve(n-3,3);

    if(selected<=5)
        b  = solve(n-5,5);
    
    if(selected<=10)
        c  =  solve(n-10,10);

    return a+b+c;
}

int solveMem(int n, int selected,vector<vector<int>>& dp){
    if(n==0)
        return 1;

    if(n<0)
        return 0;
    
    if(dp[n][selected]!=-1)
        return dp[n][selected];
    
    int ways=0;
    
    if(selected <=3)
        ways+=  solveMem(n-3,3,dp);

    if(selected<=5)
        ways+= solveMem(n-5,5,dp);
    
    if(selected<=10)
        ways+= solveMem(n-10,10,dp);

    return dp[n][selected] = ways;

}

int solveTab(int n){

    vector<int> dp(n+1,0);
    dp[0] = 1;

    for(int i=3 ; i<=n; i++)
        dp[i] += dp[i-3];

    for(int i=5; i<=n; i++)
        dp[i] += dp[i-5];

    for(int i=10; i<=n; i++)
        dp[i] += dp[i-10];

    return dp[n];
}

int main(){

    int n = 20;
    vector<vector<int>> dp(n+1,vector<int>(11,-1));
    //cout<<solveMem(n,0,dp);
    cout<<solveTab(n);
    return 0;
}