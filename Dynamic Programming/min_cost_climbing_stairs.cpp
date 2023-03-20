#include <iostream>
#include <vector>

using namespace std;

//Tabulation : Optimized Space
    int minCostClimbingStairs(vector<int>& cost) {
      int prev1 = cost[1];
      int prev2 = cost[0];

    for(int i=2;i<cost.size();i++){
        int current = cost[i] + min(prev1,prev2);
        prev2 = prev1;
        prev1 = current;
    }

    return min(prev1,prev2);

}

int main(){

vector<int> cost = {10,15,20};
cout<<minCostClimbingStairs(cost);    

    return 0;
}

//Tabulation Method

// int minCostClimbingStairs(vector<int>& cost) {

//     int n = cost.size();
//     int dp[n+1];
//     dp[0] = cost[0];
//     dp[1] = cost[1];

//     for (int i = 2; i < n; i++)
//     {
//         dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
//     }
    
//     return min(dp[n-1],dp[n-2]);
// }


//Dynamic Programming : Memoization
// int solve(vector<int>& cost, int dp[],int n){

//     if(n==0 || n==1)
//         return cost[n];

//     if(dp[n]!=-1)
//         return cost[n] + dp[n];
    
//     int dp[n] = cost[n] + min(solve(cost, dp, n-1), solve(cost, dp, n-2));
//     return dp[n];
// }


// int minCostClimbingStairs(vector<int>& cost) {

//         int n = cost.size();
//         int dp[n+1];

//         for(int i=0;i<n;i++)
//             dp[i] = -1;

//         int minCost = min(solve(cost,dp,n-1),solve(cost,dp,n-2));
//         return minCost;
// }


//Bruteforce Recursive Approach---------------
// int solve(vector<int> &cost, int n){

//     if(n==0)
//         return cost[0];
//     if(n==1)
//         return cost[1];
    
//     int ans = cost[n] + min(solve(cost,n-1), solve(cost,n-2));

//     return ans;
//}

// int minCostClimbingStairs(vector<int>& cost) {

//     int n = cost.size();

//     //0 index or 1 index
//     int minCost = min(solve(cost,n-1), solve(cost,n-2));
//     return minCost;
// }

