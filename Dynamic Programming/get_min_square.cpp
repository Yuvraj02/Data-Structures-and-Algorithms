#include <iostream>
#include <vector>
using namespace std;

//DP : Recursion + Memoization
int MinSquares(int n,vector<int> &dp)
{
    if(n==0)
        return 0;
   

    if(dp[n]!=INT32_MAX)
        return dp[n];
    
    for (int i = 1; i*i<=n; i++)
    {
        int ans = MinSquares(n-(i*i),dp);
            dp[n] = min(dp[n],ans+1);
    }
    
    return dp[n];
}

int main(){

    int N = 8;
    vector<int> dp(N+1, INT32_MAX);

    dp[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        for(int j = 1; j*j<=i;j++){
            if(i-(j*j) >=0 ){
                dp[i] = min(dp[i], dp[i-(j*j)]+1);
            }
        }
    }
    
    cout<<dp[N];
   // cout<<MinSquares(N,dp);

    return 0;
}

//Recursion
// int minSquares(int n){

//     if(n==0)
//         return 0;

//     if(n<0)
//         return INT32_MIN;

//     int mini = INT32_MAX;

//     for (int i = 1; i <= n; i++)
//     {
//         int ans = minSquares(n-(i*i));

//         if(ans!=INT32_MIN)
//             mini = min(mini,ans+1);
//     }
    
//     return mini;
// }
