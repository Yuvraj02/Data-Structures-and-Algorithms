#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<vector<int>> &A, int i, int j,int &maxSquare){
    if(i>=A.size() || j>=A[0].size()){
        return 0;
    }

    //Check for right side
    int right = solve(A,i,j+1,maxSquare);
    //Check for diagonal right
    int diagRight = solve(A,i+1,j+1,maxSquare);
    //Check for down
    int down = solve(A,i+1,j,maxSquare);

    if(A[i][j]==1){
        int ans = 1 + min({right,diagRight,down});
        //Store answer at each step
        maxSquare = max(maxSquare,ans);
        return ans;
    }else{
        return 0;
    }
}

// int maxSquare(int n, int m, vector<vector<int>> mat){
//         // code here
//     int maxSquare = INT32_MIN;
//     solve(mat,0,0,maxSquare);
//     return maxSquare;
//     vector<vector<int>> dp(n+1,vector<int>(m+1, 0));

//     dp[n][m] = 0;
//     int maxSquare = INT32_MIN;

//     for(int i=n-1;i>=0;i--){
//         for(int j = m-1;j>=0;j--){
//              //Check for right side
//         int right = dp[i][j+1];
//             //Check for diagonal right
//         int diagRight = dp[i+1][j+1];
//             //Check for down
//         int down = dp[i+1][j];

//         if(mat[i][j]==1){
//             dp[i][j] = 1 + min({right,diagRight,down});
//             //Store answer at each step
//             maxSquare = max(maxSquare,dp[i][j]);
            
//         }else{
//             dp[i][j]=0;
//         }

//         }
//     }
//     return maxSquare;

// }

 int maxSquare(int n, int m, vector<vector<int>> mat){

    vector<int> curr(m+1,0);
    vector<int> next(m+1,0);
    int maxSquare = INT32_MIN;
     for(int i=n-1;i>=0;i--){
        for(int j = m-1;j>=0;j--){
             //Check for right side
        int right = curr[j+1];
            //Check for diagonal right
        int diagRight = next[j+1];
            //Check for down
        int down = next[j];

        if(mat[i][j]==1){
            curr[j] = 1 + min({right,diagRight,down});
            //Store answer at each step
            maxSquare = max(maxSquare,curr[j]);
            
        }else{
            curr[j]=0;
        }
            next = curr;
        }
    }
    return next[0];
 }

int main(){

    int n = 2, m=2;

    vector<vector<int>> A = {{1, 1}, 
                            {1, 1}};

    cout<<maxSquare(n,m,A);
    return 0;
}