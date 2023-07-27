#include <iostream>
#include <vector>

using namespace std;

int solve(int i, int j, string &a,vector<vector<int>> &dp){
        
        if(i==j)
            return 1;
        
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(a[i]==a[j])
            return dp[i][j] =  1 + solve(i+1,j,a,dp) + solve(i,j-1,a,dp);
            
        return dp[i][j] = solve(i+1,j,a,dp) + solve(i,j-1,a,dp) - solve(i+1,j-1,a,dp);
    }
    
    
    long long int  countPS(string str)
    {
       //Your code here
        int n = str.size();
       
       vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
       
       return solve(0,str.size()-1, str,dp);
    }