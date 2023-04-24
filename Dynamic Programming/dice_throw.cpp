#include <iostream>
#include <vector>

using namespace std;

long long solve(int index, int m, int n, int target,vector<vector<long long>> &dp){
        if(index>=n){
            if(target==0)
                return 1;
            else
                return 0;
        }
        if(target<0)
            return 0;
        
        if(dp[index][target]!=-1)
            return dp[index][target];
            
        long long ans = 0;
        
        for(int i=1;i<=m;i++){
            ans+=solve(index+1, m,n,target-i,dp);
        }
        dp[index][target] = ans;
        return ans;
    }
    
   long long solveTab(int M, int N, int X){
        
        vector<vector<long long>> dp(N+1, vector<long long>(X+1, 0));
        
        dp[N][0] = 1;
        
        for(int index=N-1; index>=0;index--){
            for(int target = 0; target<=X;target++){
                
                long long ans = 0;
                for(int i = 1; i<=M;i++){
                    if(target-i>=0)
                        ans+=dp[index+1][target-i];
                }
                dp[index][target] = ans;
            }
        }
        return dp[0][X];    
    }
    
    long long spaceOptimized(int M, int N, int X){
        
        
        //vector<vector<long long>> dp(N+1, vector<long long>(X+1, 0));
        
        //dp[N][0] = 1;
        
        vector<long long> curr(X+1,0);
        vector<long long> next(X+1,0);
        
        next[0] = 1;
        curr[0] = 1;
        
        for(int index=N-1; index>=0;index--){
            for(int target = 0; target<=X;target++){
                
                long long ans = 0;
                for(int i = 1; i<=M;i++){
                    if(target-i>=0)
                        ans+=next[target-i];
                }
                curr[target] = ans;
            }
            next = curr;
        }
        return next[X]; 
        
    }
    
    
long long noOfWays(int M , int N , int X) {
        // code here
        //Memoization
       // vector<vector<long long>> dp(N+1, vector<long long>(X+1, -1));
    
        return spaceOptimized(M,N,X);
}

int main(){

    int M = 2, N = 3, X = 6;
    cout<<noOfWays(M,N,X);

 return 0;   
}
