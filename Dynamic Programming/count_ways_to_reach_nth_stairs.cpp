#include <iostream>

using namespace std;

//Memoization-------------
// int countWays(int n, int dp[]){

//     if(n==1 || n==0){
//         return 1;
//     }   

//     if(dp[n]!=-1)
//         return dp[n];

//     dp[n] = countWays(n-1,dp) + countWays(n-2, dp);

//     return dp[n];
// }


//Taabulation
// int countDistinctWays(int nStairs) {
    
//     int dp[nStairs+1];

//     dp[0] = 1;
//     dp[1] = 1;

//     for(int i = 2; i<=nStairs;i++){
//         dp[i] = dp[i-1]+dp[i-2];
//     }
//     return dp[nStairs];
// }

//Most Optimized
int countDistinctWays(int nStairs) {
    
    int prev1 = 1;
    int prev2 = 1;

    for(int i=2;i<=nStairs;i++){
        int curr=(prev1+prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){

    cout<<countDistinctWays(3);

    return 0;
}