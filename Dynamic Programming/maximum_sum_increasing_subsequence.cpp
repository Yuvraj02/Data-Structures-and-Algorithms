#include <iostream>
#include <vector>

using namespace std;

// } Driver Code Ends	
	int solve(int curr, int prev, int arr[], int n,vector<vector<int>> &dp){
	    if(curr >= n)
	        return 0;
	        
	   int include =0;
	   
	   if(dp[curr][prev+1] != -1)
	        return dp[curr][prev+1];
	   
	   if(prev==-1 || arr[curr] > arr[prev])
	        include = arr[curr] + solve(curr+1, curr, arr, n,dp);
	        
	   int exclude = solve(curr+1, prev, arr,n,dp);
	   
	   return dp[curr][prev+1] = max(include,exclude);
	}
	
	int solveTab(int arr[], int n){
	    
	    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	    
	    for(int curr = n-1; curr>=0; curr--){
	        
	        for(int prev = curr-1; prev>=-1; prev--){
	            
	            int include = 0;
	            if(prev == -1 || arr[curr] > arr[prev])
	                include = arr[curr] + dp[curr+1][curr+1];
	            
	            int exclude = dp[curr+1][prev+1];
	            
	            dp[curr][prev+1] = max(include,exclude);
	            
	        }
	        
	    }
	    
	    return dp[0][0];
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n+2,vector<int>(n+2, -1));
	    //return solve(0,-1,arr,n,dp);
	       return solveTab(arr,n);
	}  

int main(){

    int N = 5, arr[] = {1, 101, 2, 3, 100}; 

    cout<<maxSumIS(arr,N);

    return 0;
}

// } Driver Code Ends