#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> weights, vector<int> values, int n, int maxWeight,vector<vector<int>> &dp) 
{
	// Write your code here
	if(n==0){
        if(weights[n] <= maxWeight) //Include
            return values[n];
        else
            return 0;
    }

	if(dp[n][maxWeight]!=-1)
        return dp[n][maxWeight];
    //Now include every element if possible
    int include=0;
    if(weights[n] <= maxWeight){
        include = values[n] + knapsack(weights,values,n-1, maxWeight-weights[n],dp);
    }

    int exclude =  knapsack(weights,values,n-1,maxWeight,dp);

    //For the current available capacity the maxValue is
    dp[n][maxWeight] = max(include,exclude);
    return dp[n][maxWeight];
}

int main(){

    vector<int> weights = {1,2,4,5};
    vector<int> values = {5,4,8,6};
    int maxWeight = 5;
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(maxWeight+1,0));
    
    for (int i = weights[0]; i <= maxWeight; i++)
    {
        if(weights[0]<=maxWeight)
            dp[0][i] = values[0];
        else
            dp[0][i] = 0;
    }
    
    for(int i = 1; i < n;i++){
        for(int j=0;j<=maxWeight;j++){
            int include=0;
            if(weights[i] <= j){
            include = values[i] + dp[i-1][j-weights[i]];
    }

        int exclude = dp[i-1][j];

        dp[i][j] = max(include,exclude);
    }
}

        cout<<dp[n-1][maxWeight];

    return 0;
}