//{ Driver Code Starts
#include<iostream>
#include <vector>

using namespace std;

    int solve(int k, int n,vector<vector<int>> &dp){
        if(k == 1 || k==0)
            return k;
            
        if(n==1)
            return k;
        
        if(dp[k][n] != -1)
            return dp[k][n];
    
        int minMoves = INT32_MAX;
        for(int i = 1; i <= k ; i++){
            
            int moves = max(solve(i-1, n-1,dp), solve(k-i,n,dp));
            minMoves = min(minMoves, moves);
        }
        
        return dp[k][n] = minMoves + 1;
        
    }
    
   
    
    int eggDrop(int n, int k) 
    {
    
        vector<vector<int>> dp (k+1,vector<int>(n+1, -1));
        return solve(k,n,dp);
        
    }

int main()
{
    int N = 2, K = 10;
    cout<<eggDrop(N,K);
    return 0;
}
