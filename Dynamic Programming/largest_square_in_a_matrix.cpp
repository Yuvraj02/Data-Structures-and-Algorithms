#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int i,int j, int n, int m , vector<vector<int>> &mat, int &largest_square,vector<vector<int>> &dp){
            
        if(i>=n || j >= m)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int right = solve(i,j+1,n,m,mat,largest_square,dp);
        
        int diag_down_right = solve(i+1,j+1,n,m,mat,largest_square,dp);
        
        int down = solve(i+1,j,n,m,mat,largest_square,dp);
        
        int ans = 0;
        if(mat[i][j] == 1){
            ans = 1 + min({right,diag_down_right,down});
            largest_square = max(largest_square, ans);
        }
        
        return dp[i][j] = ans;
        
    }

    int solveTab(int n, int m, vector<vector<int>> &mat){
        
        int largest_square = 0;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        
        for(int i = n-1; i>=0;i--){
            for(int j = m-1; j>=0;j--){
                
                int right = dp[i][j+1];
        
                int diag_down_right = dp[i+1][j+1];
        
                int down = dp[i+1][j];
        
                int ans = 0;
                if(mat[i][j] == 1){
                    ans = 1 + min({right,diag_down_right,down});
                    largest_square = max(largest_square, ans);
                }
        
                dp[i][j] = ans;
            }
        }
        
        return largest_square;
    }
    
    int spaceOptim(int n, int m, vector<vector<int>> &mat){
        
         int largest_square = 0;
        
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
        
        
        for(int i = n-1; i>=0;i--){
            for(int j = m-1; j>=0;j--){
                
                int right = curr[j+1];
        
                int diag_down_right = next[j+1];
        
                int down = next[j];
        
                int ans = 0;
                if(mat[i][j] == 1){
                    ans = 1 + min({right,diag_down_right,down});
                    largest_square = max(largest_square, ans);
                }
        
                curr[j] = ans;
            }
            next = curr;
        }
        
        return largest_square;
        
        
    }

    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int largest_square = 0;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        //solve(0,0,n,m,mat,largest_square,dp);
        //return largest_square;
        //return solveTab(n,m,mat);
        return spaceOptim(n,m,mat);
    }

int main(){

    int n = 2, m=2;

    vector<vector<int>> A = {{1, 1}, 
                            {1, 1}};

    cout<<maxSquare(n,m,A);
    return 0;
}