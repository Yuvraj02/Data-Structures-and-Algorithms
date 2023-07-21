 #include <vector>
 #include <iostream>
 using namespace std;
 
 int solve(vector<int> &coins, int amount,vector<int> &dp){

        if(amount == 0 )
            return 0;
        
        if(amount < 0)
            return 1e5;

        if(dp[amount] != -1)
            return dp[amount];
        
        int ans = 0;
        int mini = 1e5;

        for(int i = 0; i<coins.size();i++){
            ans = 1 + solve(coins, amount-coins[i],dp);
            mini = min(mini,ans);
        }
        
        return dp[amount] =  mini;
    }

    int coinChange(vector<int>& coins, int amount) {
         vector<int> dp(amount+1, -1);
        int ans = solve(coins,amount,dp);
       
        return ans == 1e5 ? -1 : ans;
    }

    int main(){

        vector<int> coins = {1,2,5};
        int amount = 11;

        return 0;
    }