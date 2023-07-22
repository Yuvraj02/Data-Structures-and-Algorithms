#include <iostream>
#include <vector>

using namespace std; 
 
 bool isSafe(int x, int y, int m, int n){
        if((x>=0 && x<m) && (y>=0 && y<n))
            return true;

        return false;
    }

    int solve(int x, int y,int m, int n,vector<vector<int>> &dp){
       if(x==m-1 && y==n-1)
            return 1;

        if(dp[x][y]!=-1)
            return dp[x][y];

        int ways = 0;

        int next_x = x+1;
        int next_y = y+1;

        //cout<<x<<" "<<y<<" "<<endl; 
        //Go down
        if(isSafe(next_x,y,m,n))
            ways+=solve(next_x,y,m,n,dp);
        
        //Go Right
        if(isSafe(x,next_y,m,n))
            ways+=solve(x,next_y,m,n,dp);

        return dp[x][y] = ways;
    
    }

    int solveMem(int m,int n){
       vector<vector<int>> dp(m,vector<int>(n,-1));
       return solve(0,0,m,n,dp);
    }

    int solveTab(int m, int n){
       vector<vector<int>> dp(m+1,vector<int>(n+1,1));

       for(int x = m-2 ; x>=0 ;x--){
           for(int y=n-2; y>=0;y--){

                int ways = 0;
                //Go down
                if(isSafe(x+1,y,m,n))
                    ways+=dp[x+1][y];
        
                 //Go Right
                if(isSafe(x,y+1,m,n))
                    ways+=dp[x][y+1];

                dp[x][y] = ways;
           }
       }
    return dp[0][0];
    }

    int spaceOptim(int m, int n){
        vector<int> next(n+1,1);
        vector<int> curr(n+1,1);

         for(int x = m-2 ; x>=0 ;x--){
           for(int y = n-2; y>=0;y--){

                int ways = 0;
                //Go down
                if(isSafe(x+1,y,m,n))
                    ways+=next[y];
        
                 //Go Right
                if(isSafe(x,y+1,m,n))
                    ways+=curr[y+1];

                curr[y] = ways;
           }
           next = curr;
       }
       return next[0];
    }       

    int uniquePaths(int m, int n) {
    
    //return solveTab(m,n);
    return spaceOptim(m,n);
    }