#include <iostream>
#include <vector>

using namespace std;

//Function Prototypes

int maxProfit(vector<int>&);
int solve(int, vector<int>&, int, int, vector<vector<vector<int>>>&);
int solveTab(vector<int>&);
int solveOptimization(vector<int>&);


int main(){

    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<maxProfit(prices);
    return 0;
}


int maxProfit(vector<int>& prices) {
        
    // int n = prices.size();
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,-1)));
        
    //return solve(0,prices,1,2,dp);
    return solveOptimization(prices);
}

int solve(int index, vector<int> &prices, int buy, int limit,vector<vector<vector<int>>> &dp){
        if(index >= prices.size())
            return 0;

        if(limit==0)
            return 0;

        if(dp[index][buy][limit]!= -1)
            return dp[index][buy][limit];

        int profit = 0;


        if(buy){
            //Profit = Selling Price - Buying Price
            // Profit = Selling Price + (-Buying Price)
             int bought = -prices[index] + solve(index+1, prices, 0,limit,dp);

             int notBought = solve(index+1, prices, 1, limit,dp);

             profit = max(bought,notBought);
        }else{
            int sold = prices[index] + solve(index+1, prices, 1, limit-1,dp);

            int notSold = solve(index+1, prices, 0, limit,dp);

            profit = max(sold,notSold);
        }

        return dp[index][buy][limit] = profit;
    }
    
    int solveTab(vector<int>& prices){
         int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

        for(int index = n-1;index>=0;index--){
            for(int buy = 0; buy<2;buy++){
                for(int limit = 1; limit<=2;limit++){
                    
                    int profit = 0;
                    if(buy){
                        int bought = -prices[index] + dp[index+1][0][limit];
                        int notBought = dp[index+1][1][limit];

                        profit = max(bought, notBought);
                    }else{
                        int sold = prices[index] + dp[index+1][1][limit-1];
                        int notSold = dp[index+1][0][limit];

                        profit = max(sold,notSold);
                    }

                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    int solveOptimization(vector<int> &prices){

        
        int n = prices.size();
        //vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        vector<vector<int>> next(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));

        for(int index = n-1;index>=0;index--){
            for(int buy = 0; buy<2;buy++){
                for(int limit = 1; limit<=2;limit++){
                    
                    int profit = 0;
                    if(buy){
                        int bought = -prices[index] + next[0][limit];
                        int notBought = next[1][limit];

                        profit = max(bought, notBought);
                    }else{
                        int sold = prices[index] + next[1][limit-1];
                        int notSold = next[0][limit];

                        profit = max(sold,notSold);
                    }

                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }