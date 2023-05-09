#include <iostream>
#include <vector>

using namespace std;

int solve(int i, vector<int> &arr, int &k, int rem, vector<vector<int>>&dp){

    if(i>=arr.size())
        return 0;

    if(dp[i][rem] != -1)
        return dp[i][rem];

    int ans;
    if(arr[i] > rem){
        ans = (rem+1) * (rem+1) + solve(i+1,arr,k,k-arr[i]-1, dp);
    }else{
        int choice1 = (rem+1) * (rem+1) + solve(i+1,arr,k,k-arr[i]-1, dp);
        
        int choice2 = solve(i+1,arr,k,rem-arr[i]-1,dp);

        ans = min(choice1,choice2);
    }
    
    return dp[i][rem] = ans;
}

int solveTab(vector<int>&nums, int k){
    int n = nums.size()+1;
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    
    for(int i = n-1; i>=0; i--){
        for(int rem = 0; rem <= k;rem++){
            int ans;
            
            if(nums[i] > rem){
                ans = (rem+1) * (rem+1) + dp[i+1][k-nums[i]-1];
            }else{
                int choice1 = ans = (rem+1) * (rem+1) + dp[i+1][k-nums[i]-1];
                
                int choice2 = dp[i+1][rem-nums[i]-1];
                
                ans = min(choice1,choice2);
            }
            dp[i][rem] = ans;
        }
    }
    return dp[0][k];
}


int solveWordWrap(vector<int>nums, int k) 
{ 
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(0, nums,k,k,dp);
       
} 

int main(){

    vector<int> nums = {10 ,6 ,5 ,3 ,1 ,10, 8, 2}; 
    int k = 12;

    cout<<solveWordWrap(nums,k)<<endl;

    return 0;
}