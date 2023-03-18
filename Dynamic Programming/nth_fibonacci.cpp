#include <iostream>

using namespace std;

int fibo(int n, int dp[]){

    if(n==0 || n==1)
        return n;
    
    if(dp[n]!=-1)
        return dp[n];

    dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
    return dp[n];
}

int main(){

    int N = 6;

    int dp[N+1]; 

    for(int i =0; i<=N;i++)
        dp[i] = -1;


    cout<<fibo(N, dp);

    return 0;
}