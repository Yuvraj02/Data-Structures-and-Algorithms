#include <iostream>
#include <vector>

using namespace std;

int solve(int curr, int prev, vector<int> &arr, bool isSmaller,vector<vector<vector<int>>> &dp){
	            
	       if(curr>=arr.size())
	           return 0;
	       
	       if(dp[curr][prev+1][isSmaller] != -1)
	            return dp[curr][prev+1][isSmaller];
	       
	       int include = 0;
	       
	       if(prev==-1){
	           include = 1 + solve(curr+1,curr,arr,!isSmaller,dp);
	       }
	       
	       if(isSmaller){
	           //Means if the curren element should be smaller than prev
	           if(arr[curr] < arr[prev])
	                include = 1 + solve(curr+1,curr,arr,!isSmaller,dp);
	       }else{
	           
	           if(arr[curr] > arr[prev])
	                include = 1 + solve(curr+1,curr,arr,!isSmaller,dp);
	       }
	       
	       int exclude = solve(curr+1,prev,arr,isSmaller,dp);
	       
	       dp[curr][prev+1][isSmaller] = max(include,exclude);
	        
	    }
	
		int AlternatingaMaxLength(vector<int>&arr){
		    // Code here
		    int n = arr.size();
		    //vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
		    
		   // int ans1 = solve(0,-1,nums,true,dp);
		    //int ans2 = solve(0,-1,nums,false,dp);
		    
		    
		    int inc = 1;
		    int dec = 1;
		    
		    for(int i = 1; i<arr.size();i++){
		        
		        if(arr[i] > arr[i-1])
		            inc = dec+1;
		        else if(arr[i] < arr[i-1])
		            dec = inc+1;
		        
		    }
		    
		    return max(inc,dec);
		}