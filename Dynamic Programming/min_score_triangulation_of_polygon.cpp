#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minScoreTriangulation(vector<int> &values,int i, int j,vector<vector<int>> &dp){

    if(i+1==j)
        return 0;

    if(dp[i][j]!=INT32_MAX)
        return dp[i][j];

    for(int k = i+1; k<j;k++){
        dp[i][j] = min({dp[i][j],values[i]*values[j]*values[k] + minScoreTriangulation(values,i,k,dp)+minScoreTriangulation(values,k,j,dp)});
    }
    return dp[i][j];
}

int main(){

    vector<int> values = {3,7,4,5};
    int n = values.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,INT32_MAX));
    

    cout<<minScoreTriangulation(values,0,n-1,dp);

    return 0;
}