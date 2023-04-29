#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>&, int);

int main(){
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    cout<<maxProfit(prices,fee);
    return 0;
}

 int solve(int index, vector<int>& prices, int buy, int fee){
        if(index >= prices.size())
            return 0;

        int profit = 0;
        if(buy){
            int bought = -prices[index] + solve(index+1, prices, 0,fee);
            int notBought = solve(index+1, prices, 1, fee);

            profit = max(bought, notBought);
        }else{
            int sold = prices[index] + solve(index+1, prices, 1, fee);
            int notSold = solve(index+1, prices,0,fee);

            profit = max(sold-fee, notSold);
        }        

        return profit;
    }

    int solveMem(int index, vector<int>& prices, int buy, int fee,vector<vector<int>> &dp){
         if(index >= prices.size())
            return 0;
        
        if(dp[index][buy]!=-1)
            return dp[index][buy];

        int profit = 0;
        if(buy){
            int bought = -prices[index] + solveMem(index+1, prices, 0,fee,dp);
            int notBought = solveMem(index+1, prices, 1, fee,dp);

            profit = max(bought, notBought);
        }else{
            int sold = prices[index] + solveMem(index+1, prices, 1, fee,dp);
            int notSold = solveMem(index+1, prices,0,fee,dp);

            profit = max(sold-fee, notSold);
        }        

        return dp[index][buy] = profit;
    }

    int solveTab(vector<int>& prices, int fee){

        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int index=n-1;index>=0;index--){
            for(int buy = 0;buy<2;buy++){
                int profit = 0;
        if(buy){
            int bought = -prices[index] + dp[index+1][0];
            int notBought = dp[index+1][1];

            profit = max(bought, notBought);
        }else{
            int sold = prices[index] + dp[index+1][1];
            int notSold = dp[index+1][0];

            profit = max(sold-fee, notSold);
        }

        dp[index][buy] = profit;        

            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));

        return solveTab(prices,fee);   
    }