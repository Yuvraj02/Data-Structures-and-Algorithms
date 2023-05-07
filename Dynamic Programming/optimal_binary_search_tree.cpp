#include <iostream>
#include <vector>

using namespace std;



int solve(int i, int j, int freq[]){
        
        if(i>j)
            return 0;
        
        if(i==j)
            return freq[i];
            
        int minOps = INT32_MAX;
        
        int fsum = 0;
        for(int l = i; l<=j; l++){
            fsum+=freq[l];
        }
        
        for(int k = i; k<=j;k++){
            
            int cost = solve(i,k-1,freq) + solve(k+1,j,freq);
            
            minOps = min(minOps,cost);
        }
        
        return minOps+fsum;
    }
    
    int solveMem(int i, int j, int freq[],vector<vector<int>> &dp){
        
        if(i>j)
            return 0;
            
        if(i==j)
            return freq[i];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int freq_sum = 0,minSearch = INT32_MAX;
        
        for(int l = i; l<=j;l++)
            freq_sum+=freq[l];
        
        for(int k = i;k<=j;k++){
            int cost = solveMem(i,k-1,freq,dp) + solveMem(k+1,j,freq,dp);
            
            minSearch = min(cost,minSearch);
        }
        
        dp[i][j] = minSearch + freq_sum;
        return dp[i][j];
    }
    
    int solveTab(int freq[], int n){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=0;i<n+1;i++)
            dp[i][i] = freq[i];
            
        for(int i = n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                
        int freq_sum = 0,minSearch = INT32_MAX;
        
        for(int l = i; l<=j;l++)
            freq_sum+=freq[l];
        
        for(int k = i;k<=j;k++){
            
            int cost = dp[i][k-1] + dp[k+1][j];
            
            minSearch = min(cost,minSearch);
        }
        
        dp[i][j] = minSearch + freq_sum;
                
            }
        }
        return dp[0][n-1];
        
    }
    
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
        //return solve(0,n-1,freq);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        //return solveMem(0,n-1,freq,dp);
        return solveTab(freq,n);
    }

    int main(){

        int keys[] = {10,20};
        int freq[] = {34,50};

        cout<<optimalSearchTree(keys,freq,2);

        return 0;
    }