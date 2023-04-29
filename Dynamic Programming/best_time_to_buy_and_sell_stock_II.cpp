#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>&);

int main(){
    vector<int> prices = {1,3,2,8,4,9};
    cout<<maxProfit(prices);
    return 0;
}

int solveMem(int index, vector<int>& prices, int buy,vector<vector<int>>& dp){
        if(index >= prices.size())
            return 0;

        int profit = 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];

        if(buy){
            //Profit  = Sell + (-Buy)
            int bought = -prices[index] + solveMem(index+1, prices,0,dp);

            int notBought = solveMem(index+1, prices, 1,dp);

            profit = max(bought,notBought);
        }else{
            //Profit = Sell + (-Buy)
            int sold = prices[index] + solveMem(index+1, prices,1,dp);

            int notSold = solveMem(index+1, prices,0,dp);

            profit = max(sold,notSold);
        }

      return dp[index][buy] = profit;

    }

    int solveTab(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        for(int index=n-1; index>=0;index--){
            for(int buy=0;buy<2;buy++){

                int profit = 0;

                if(buy){
                    int bought = -prices[index] + dp[index+1][0];
                    int notBought = dp[index+1][1];

                    profit = max(bought,notBought);
                }else{
                    int sold = prices[index] + dp[index+1][1];
                    int notSold = dp[index+1][0];

                    profit = max(sold,notSold);
                }

                dp[index][buy] = profit;
            }
        }
    return dp[0][1];
    }

    int solveOptimized(vector<int>& prices){
        int n = prices.size();
        //vector<vector<int>> dp(n+1, vector<int>(2,0));
        vector<int> next(2,0);
        vector<int> curr(2,0);


        for(int index=n-1; index>=0;index--){
            for(int buy=0;buy<2;buy++){

                int profit = 0;

                if(buy){
                    int bought = -prices[index] + next[0];
                    int notBought = next[1];

                    profit = max(bought,notBought);
                }else{
                    int sold = prices[index] + next[1];
                    int notSold = next[0];

                    profit = max(sold,notSold);
                }

                curr[buy] = profit;
            }
            next = curr;
        }
    return next[1];
    }

    int maxProfit(vector<int>& prices) {
       // int n = prices.size();
       // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        

        //return solve(0,prices,1,dp);
        return solveTab(prices);
    }