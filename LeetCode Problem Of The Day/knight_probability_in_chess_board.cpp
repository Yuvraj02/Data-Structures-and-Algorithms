#include <iostream>
#include <vector>

using namespace std; 
 
bool check(int x, int y, int n){
        if((x>=0 && x<n) && (y>=0 && y<n))
            return true;

        return false;
    }

    double solve(int x, int y, int n, int k, int X[], int Y[],vector<vector<vector<double>>> &dp){

        if(check(x,y,n)==false)
            return 0;

        if(k==0)
            return 1;
        if(dp[x][y][k]!=-1)
            return dp[x][y][k];

        double res = 0;

        for(int i = 0; i<8;i++){
            int next_x = x + X[i];
            int next_y = y + Y[i];

           res += solve(next_x,next_y,n,k-1,X,Y,dp);
        }

        return dp[x][y][k] = res/8.0;
    }

    double knightProbability(int n, int k, int row, int column) {
        int X[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
        int Y[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };
        
        //What a DECLARATION MAN!!
        vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));

        return solve(row,column,n,k,X,Y,dp);
        
    }