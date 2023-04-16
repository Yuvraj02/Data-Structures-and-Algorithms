#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> values, int i,int j, vector<vector<int>> &dp){

if(i+1==j)
        return 0;

    if(dp[i][j]!=INT32_MAX)
        return dp[i][j];

    for(int k = i+1; k<j;k++){
        dp[i][j] = min({dp[i][j],values[i]*values[j]*values[k] + solve(values,i,k,dp)+solve(values,k,j,dp)});
    }
    return dp[i][j];
}

int minScoreTriangulation(vector<int> &values){
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n,0));
    // return solve(values,0,n-1,dp); 

}

int main(){

    vector<int> values = {3,7,4,5};
    cout<<minScoreTriangulation(values);   

    return 0;
}