#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    int solve(int n, int m, int i, int j,vector<vector<int>>&M){
        if((i<0) || (i>=n) || (j>=n))
            return 0;
            
        int right = solve(n,m,i,j+1,M);
        
        int diagDownRight = solve(n,m,i+1,j+1,M);
        
        int diagUpRight = solve(n,m,i-1,j+1,M);
        
        return M[i][j] + max({right,diagDownRight,diagUpRight});
        
        
    }
    
    int solveMem(int n, int m, int i, int j, vector<vector<int>> &M,vector<vector<int>> &dp){
        
        
        if(i<0 || (i>=n) || (j>=m))
            return 0;
            
            if(dp[i][j] != -1)
                return dp[i][j];
            
            int rightDiagUp = solveMem(n,m,i-1,j+1,M,dp);
            
            int right = solveMem(n,m,i,j+1,M,dp);
            
            int rightDiagDown = solveMem(n,m,i+1,j+1,M,dp);
            
            return dp[i][j] = M[i][j] + max({rightDiagUp, right,rightDiagDown});
    }


    int maxGold(int n, int m, vector<vector<int>> M)
    {
       
        int maxAmount = 0;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1, -1));
        
        for(int i = 0; i<n;i++){
            
            //maxAmount = max(maxAmount, solve(n, m, i,0,M));
            maxAmount = max(maxAmount, solveMem(n,m,i,0,M,dp));
        }
        
        return maxAmount;
    }

int main(){

    vector<vector<int>> grid = {{1, 3, 3},
                                {2, 1, 4},
                                {0, 6, 4}};
    cout<<maxGold(grid.size(),grid[0].size(),grid);
    return 0;
}