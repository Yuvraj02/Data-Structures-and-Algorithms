#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//Optimized Solution
bool equalPartition(int N, int arr[])
    {
        int total = 0;
        for(int i =0;i<N;i++)
            total+=arr[i];
            
        if(total&1)
            return 0;
            
        int t = total/2;        
        vector<int> curr(t+1,0);
        vector<int> next(t+1,0);
        
        curr[0] = 1;
        next[0] = 1;
        
        
        for(int index = N-1; index >=0 ;index--){
            for(int target = 0; target<=t;target++){
                
                bool include = 0;
                if(target-arr[index]>=0)
                    include = next[target-arr[index]];
                    
                bool exclude = next[target];
                
                curr[target] = include||exclude;
            }
            next = curr;
        }
        return next[t];
    }

int main(){

    const int N = 4;
    
    int arr[N] = {1,5,11,5};

    cout<<boolalpha<<equalPartition(N,arr);
    return 0;
}

int solve(int index,int N,int arr[], int target,vector<vector<int>>& dp){
        if(index>=N)
            return false;
        if(target<0)
            return false;
        if(target==0)
            return true;
            
        if(dp[index][target]!=-1)
            return dp[index][target];
        
        int include = solve(index+1, N,arr,target - arr[index],dp);
        
        int exclude = solve(index+1, N,arr,target,dp);
        
        return dp[index][target] = (include || exclude);
    }

    int solveTab(int N, int arr[])
    {
        int total = 0;
        for(int i =0;i<N;i++)
            total+=arr[i];
            
        if(total&1)
            return 0;
            
        int t = total/2;
        
        vector<vector<int>> dp(N+1, vector<int>(t+1,0));
        
        for(int i=0;i<=N;i++){
            dp[i][0] = 1;
        }
        
        for(int index = N-1; index >=0 ;index--){
            for(int target = 0; target<=t;target++){
                
                bool include = 0;
                if(target-arr[index]>=0)
                    include = dp[index+1][target-arr[index]];
                    
                bool exclude = dp[index+1][target];
                
                dp[index][target] = include||exclude;
            }
        }
        return dp[0][t];

       // return solve(0,N,arr,target,dp);
}