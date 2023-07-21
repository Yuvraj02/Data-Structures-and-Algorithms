 #include <iostream>
 #include <vector>
 using namespace std;
 
 int solve(int i, int j, string str,vector<vector<int>> &dp){
	        if(i==str.size() || j==str.size())
	            return 0;
	        
	        if(dp[i][j]!=-1)
	            return dp[i][j];
	    
	        if(str[i]==str[j] && i!=j){
	            return dp[i][j] = 1 + solve(i+1,j+1,str,dp);
	        }     
	       
	       return dp[i][j] = max(solve(i+1,j,str,dp), solve(i,j+1,str,dp));
	    }
	    
	    int solveTab(string str){
	        int n = str.size();
	        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
	        
	        for(int i = n-1; i>=0 ;i--){
	            for(int j = n-1; j>=0;j--){
	                
	                if(str[i]==str[j] && i!=j)
	                    dp[i][j] = 1 + dp[i+1][j+1];
	                else
	                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
	            }
	        }
	        
	        return dp[0][0];
	        
	    }
	
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
		    //return solve(0,0,str,dp);
		    return solveTab(str);
		}