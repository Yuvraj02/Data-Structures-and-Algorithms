#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

 int solve(int h){
        if(h==0 || h==1)
            return 1;
            
        return solve(h-1) * (2*solve(h-2) + solve(h-1));
    }
    
    long long int solveMem(int h,vector<long long int> &dp){
        if(h==0 || h==1)
            return 1;
            
        if(dp[h]!=-1)
            return dp[h];
        
         dp[h] = (solve(h-1) * (2*solve(h-2)%MOD + solve(h-1)%MOD))%MOD;
        return dp[h]%MOD;
    }
    
    long long int solveTab(int h){
        vector<long long int> dp(h+1, 0);
        
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i<=h;i++){
            dp[i] = (dp[i-1] * (2*dp[i-2]%MOD + dp[i-1]%MOD))%MOD;
        }
        
        return dp[h];
    }
    
    long long int spaceOptim(int h){
        long long int prev1 = 1;
        long long int prev2 = 1;
        
        for(int i=2;i<=h;i++){
            int curr = (prev1 * (2*(prev2)%MOD + prev1%MOD))%MOD;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
  
    long long int countBT(int h) { 
        // code here
        //return solve(h);
        vector<long long int> dp(h+1, -1);
        //return solveMem(h,dp);
        //return solveTab(h);
        return spaceOptim(h);
    }

int main(){

    cout<<countBT(7);

    return 0;
}