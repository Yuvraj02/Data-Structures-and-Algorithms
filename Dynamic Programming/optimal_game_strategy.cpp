#include <iostream>
#include <vector>

using namespace std;


 int solve(int i, int j, int arr[], int N,vector<vector<int>>& dp){
        
        if(i>=N || j<0 || i > j)
            return 0;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
        //If user chooses from left
        int chooseLeft = arr[i] + min(solve(i+2,j,arr,N,dp), solve(i+1,j-1,arr,N,dp));
        
        //If user chooses from right
        int chooseRight = arr[j] + min(solve(i,j-2,arr,N,dp), solve(i+1,j-1,arr,N,dp));
        
        return dp[i][j] = max(chooseLeft,chooseRight);
    }
    
    
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<int>> dp (n+1,vector<int>(n+1,-1));
        
        return solve(0,n-1,arr,n,dp);
    }

int main(){
    int arr[] = {5,3,7,10};
    cout<<maximumAmount(arr,4);

    return 0;
}