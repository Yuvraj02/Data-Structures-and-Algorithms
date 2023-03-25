#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;


int main(){
    //Space Optimization-------
    int n = 3;

    long long int prev1 = 1;
    long long int prev2 = 0;

    for(int i = 3; i <=n ;i++){
        int current = (i-1) * (prev2 + prev1);
        prev2 = prev1;
        prev1 = current;
    }

    cout<< prev1;
    return 0;
}

//Tabulation------------
// vector<int> dp(n+1,-1);
    // dp[1] = 0;
    // dp[2] = 1;

    // long long int prev1 = 1;
    // long long int prev2 = 1;

    // for(int i = 3; i<=n;i++){
    //     dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
    // } 

//DP Memoization

// long long int solve(int n, vector<int>& dp){

//     if(n==1)
//         return 0;
//     if(n==2)
//         return 1;

//     if(dp[n]!=-1)
//         return dp[n];

//    dp[n] = ((n-1)%MOD) * ((solve(n-1,dp)%MOD) + (solve(n-2,dp)%MOD))%MOD;

//     return dp[n];
// }

//Recursion
// long long int countDerangements(int n) {
//     if (n==1)
//         return 0;

//     if(n==2)
//         return 1;


//     int ans = ((n-1)%MOD * ((countDerangements(n-1)%MOD) + (countDerangements(n-2)%MOD))%MOD);
//     return ans;
// }

