#include <iostream>
#include <vector>

using namespace std;

   int solve(int i, int j, int arr[]){
        if(i==j)
            return 0;
            
        int mini = INT32_MAX;
        
        for(int k = i; k<j; k++){
            
            int steps = (arr[i-1]*arr[k]*arr[j]) + solve(i,k,arr) + solve(k+1,j,arr);
            
            mini = min(mini,steps);
        }
        
        return mini;
        
    }
    
    int solveMem(int i, int j, int arr[],vector<vector<int>> &dp){
        
        if(i==j)
            return 0;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int minOps = INT32_MAX;
        
        for(int k = i; k<j; k++){
            
            int steps = (arr[i-1]*arr[k]* arr[j]) + solveMem(i,k,arr,dp) + solveMem(k+1,j,arr,dp);
            
            minOps = min(minOps, steps);
        }    
            
            return dp[i][j] = minOps;
    }
    
    int solveTab(int N, int arr[]){
        
        vector<vector<int>> dp(N+1,vector<int>(N+1,0));
        
        
        for(int i = N-1; i>=1;i--){
            for(int j = i+1;j<N;j++){
                
                int minOps = INT32_MAX;
                
                for(int k = i; k<=j-1;k++){
                    
                    int steps = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                    
                    minOps = min(steps,minOps);
                }
                    
                dp[i][j] = minOps;
            }
        }
     
     return dp[1][N-1];
        
    }

    int matrixMultiplication(int N, int arr[])
    {
        
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        
       // return solveMem(1,N-1,arr,dp);
        return solveTab(N,arr);
    }

int main(){
  
    int arr[] = {40, 20, 30, 10, 30};
    cout<<matrixMultiplication(5,arr);
    return 0;
}