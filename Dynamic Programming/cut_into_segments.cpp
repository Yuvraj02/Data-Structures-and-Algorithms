#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int solve(int n, int x, int y, int z,vector<int> &dp){
        
        if(n==0)
            return 0;
        
        if(n<0)
            return INT_MIN;
            
        if(dp[n]!=-1)
            return dp[n];
            
        int a = 1 + solve(n-x, x,y,z,dp);
        
        int b = 1 + solve(n-y, x,y,z,dp);
        
        int c = 1 + solve(n-z, x,y,z,dp);
        
        return dp[n] = max({a,b,c});
        
    }
    
    int solveTab(int n, int x, int y, int z){
        
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for(int i = 1; i<=n;i++){
            
            int a=INT_MIN,b=INT_MIN,c=INT_MIN;
            
            if(i-x>=0)
                 a = 1 + dp[i-x];
            if(i-y>=0)
                 b = 1 + dp[i-y];
            if(i-z>=0)
                 c = 1 + dp[i-z];
            
            dp[i] = max({a,b,c});
        }
        return dp[n];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        //vector<int> dp(n+1,-1);
        //int ans = solve(n,x,y,z,dp);
        
        int ans = solveTab(n,x,y,z);
        return ans < 0 ? 0 : ans;
    }

int main(){

    int n = 7, x = 5, y=2,z=2;

    cout<<maximizeTheCuts(n,x,y,z)<<endl;

    return 0;
}