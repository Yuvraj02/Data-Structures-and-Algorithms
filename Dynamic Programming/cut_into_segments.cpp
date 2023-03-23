#include <iostream>
#include <vector>
using namespace std;


//Recursion + Memoization
int cut(int n, int x, int y, int z, vector<int> &dp){

    if(n==0)
        return 0;
    
    if(n<0)
        return INT32_MIN;
    
    if(dp[n]!=-1)
        return dp[n];

    int ans,maxi = INT32_MIN;
    
    //Solve for x
    ans = cut(n-x, x, y, z, dp);
    if(ans!=INT32_MIN){
        maxi = max(maxi, 1+ans);
    }
    //Solve for y
    ans = cut(n-y, x, y, z,dp);
    if(ans!=INT32_MIN){
        maxi = max(maxi, 1+ans);
    }
    //Solve for z
    ans = cut(n-z, x, y, z,dp);
    if(ans!=INT32_MIN){
        maxi = max(maxi, 1+ans);
    }

    dp[n] = maxi;
    return dp[n];
}

int main(){

    int n = 7, x = 5, y=2,z=2;
    vector<int> dp(n+1, INT32_MIN);

	dp[0] = 0;

	//int ans = cut(n,x,y,z,dp);
    
    //------Tabulation
	for(int i=1; i <= n;i++){
       if(i-x>=0)
        dp[i] = max(dp[i], dp[i-x]+1);

       if(i-y>=0)
        dp[i] = max(dp[i], dp[i-y]+1);

        if(i-z>=0)
        dp[i] = max(dp[i], dp[i-z]+1);
	}

    cout<<INT32_MIN<<endl;

    return 0;
}