#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool comparator(vector<int> &a, vector<int> &b){
    return a[1]<b[1];
}

    int solve (vector<vector<int>> &a, int i, int j,vector<vector<int>> &dp){
        if(i>=a.size())
            return 1;

        if(dp[i][j]!=-1)
            return dp[i][j];

          int include = 0;
          if(a[i][0] > a[j][1]){
              include = 1 + solve(a,i+1, i,dp);
          }  
            int exclude = solve(a,i+1,j,dp);

        return dp[i][j] = max(include,exclude);
    }

    int solveTab(vector<vector<int>>&a){
        sort(a.begin(),a.end(),comparator);
        int n = a.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 1));

        for(int i = n-1; i>=1;i--){
            for(int j = 0; j<i;j++){
                    
          int include = 0;
          if(a[i][0] > a[j][1]){
              include = 1 + dp[i+1][i];
          }  
            int exclude = dp[i+1][j];

            dp[i][j] = max(include,exclude);
            }
        }
   return dp[1][0];
    }

    int solveOptim(vector<vector<int>>&a){
        sort(a.begin(),a.end(),comparator);
        int n = a.size();
        //vector<vector<int>> dp(n+1, vector<int>(n+1, 1));
        vector<int> curr(n+1,1);
        vector<int> next(n+1,1);

        for(int i = n-1; i>=1;i--){
            for(int j = 0; j<i;j++){
                    
          int include = 0;
          if(a[i][0] > a[j][1]){
              include = 1 + next[i];
          }  
            int exclude = next[j];

            curr[j] = max(include,exclude);
            }
            next = curr;
        }
   return next[0];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end(),comparator);
        int n = pairs.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

   // return solve(pairs,1,0,dp);
   //return solveTab(pairs);
   return solveOptim(pairs);
    }

int main(){

    vector<vector<int>> pairs = {{1,2},{2,3},{3,4}};
    cout<<findLongestChain(pairs);
}