#include <iostream>
#include <vector>

using namespace std;

 bool solve(int n, int x, int y,vector<int> &dp){
        if(n==0)
            return false;
        if(n==1)
            return true;
        
        if(dp[n]!=-1)
            return dp[n];
        
        //N-1, N-X, N-Y are moves of B, if B can't win the game that means A will win
        //If A losses n-1, n-x,n-y game then he definiytely wins nth game
        bool ans;
        if(n-1>=0 && !solve(n-1,x,y,dp)) 
            ans = true;
        else if(n-x>=0 && !solve(n-x,x,y,dp)) 
            ans = true;
        else if(n-y>=0 && !solve(n-y,x,y,dp))
            ans = true;
        else
            ans = false;
        
        return dp[n] = ans;
        
    }	
	
int findWinner(int n, int x, int y)
{
		// Your code goes here
		vector<int> dp(n+1);
		dp[0] = false;
		dp[1] = true;
		
		for(int i=2; i<=n; i++){
		    
		bool ans;
        if(i-1 >= 0 && !dp[i-1]) 
            ans = true;
        else if(i-x >=0 && !dp[i-x]) 
            ans = true;
        else if(i-y >=0 && !dp[i-y])
            ans = true;
        else
            ans = false;
        
        dp[i] = ans;
		    
		}
		
		
		return dp[n];
}
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    cout<<findWinner(n,x,y);
    return 0;
}