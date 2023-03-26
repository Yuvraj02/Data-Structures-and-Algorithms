#include <iostream>
#include <vector>

using namespace std;

 int numberOfWays(int n, int k,vector<int> &dp) {
    if(n==1)
        return k;
    if(n==2)
        return k*k;

    if(dp[n]!=-1)
        return dp[n];

    dp[n] = (numberOfWays(n-2,k,dp) * (k-1)) + (numberOfWays(n-1,k,dp)*(k-1));
    return dp[n];

 }

//Recursion

// int numberOfWays(int n, int k) {

//    if(n==1)
//     return k;

//    if(n==2)
//     return k*k;

//     int ans = (numberOfWays(n-2,k) * (k-1)) + (numberOfWays(n-1,k) * (k-1));
//     return ans;
// }

int main(){
    int n = 3, k=2;
    vector<int> dp(n+1,-1);
    dp[1] = k;
    dp[2] = k*k;

    for(int i=3;i <= n; i++){
        dp[i] = (dp[i-2] * (k-1)) + (dp[i-1] * (k-1));
    }       

    cout<<dp[n];

    return 0;
}