  #include <vector>
  #include <iostream>
  #include <unordered_map>
  #include <algorithm>
  
  using namespace std;

int solveMem(int curr, vector<vector<int>> &events, int k, int n,int prev,vector<vector<vector<int>>> &dp){
        if(curr>=n || k==0)
            return 0;
        
        if(dp[curr][prev+1][k]!=-1)
            return dp[curr][prev+1][k];

        int include = 0;
        if(prev==-1 || events[curr][0] > events[prev][1]){
            include = events[curr][2] + solveMem(curr+1, events,k-1,n,curr,dp);
        }

        int exclude = solveMem(curr+1, events,k,n,prev,dp);

        return dp[curr][prev+1][k] = max(include,exclude);
    }

    // int solveMem(){
    //     int n = events.size();
    //     int prev = -1;
    //     sort(events.begin(),events.end());
    //     vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
    // }

    int solveTab(vector<vector<int>> &events, int k){
        int n = events.size();
        //int prev = -1;
        sort(events.begin(),events.end());
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,0)));

        for(int i = n-1; i>=0; i--){
            for(int prev = -1; prev < i; prev++){
                for(int l = k;l>0;l--){
                      int include = 0;
                      if(prev==-1 || events[i][0] > events[prev][1]){
                        include = events[i][2] + dp[i+1][i+1][l-1];
                      }
                      int exclude = dp[i+1][prev+1][l];
                      dp[i][prev+1][l] = max(include,exclude);
                }
            }
        }
        return dp[0][0][k];
    }

    int maxValue(vector<vector<int>>& events, int k) {
        
        return solveTab(events,k);
        //return solve(0,events,k,n,prev,dp);
    }