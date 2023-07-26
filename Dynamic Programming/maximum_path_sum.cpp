#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


int solve(int x, int y, vector<vector<int>> &matrix,int n,vector<vector<int>> &dp){
        
        if(x>=n || y>=n || y<0)
            return 0;
        
        if(dp[x][y]!=-1)
            return dp[x][y];
            
        int down = matrix[x][y] + solve(x+1,y,matrix,n,dp);
        
        int diag_right = matrix[x][y] + solve(x+1,y+1,matrix,n,dp);
        
        int diag_left = matrix[x][y] + solve(x+1,y-1,matrix,n,dp); 
        
        return dp[x][y] = max({down,diag_right,diag_left});
    }
    
    

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
       
        int max_val = INT_MIN;
        for(int i = 0; i < N; i++){
                
            int val = solve(N,Matrix,dp,i);
            
            max_val = max(max_val,val);
        }
        
        return max_val;
    }