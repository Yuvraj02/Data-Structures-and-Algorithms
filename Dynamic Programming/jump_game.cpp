#include <iostream>
#include <vector>

using namespace std; 
 

bool solve(int i, vector<int>& nums, int target_index,vector<vector<int>> &dp){

        if(i==1){
            if(i+nums[i] >= target_index){
                return true && solve(i-1,nums,i,dp);
            }
            return solve(i-1,nums,target_index,dp);
        }

        if(i==0){
            if(i+nums[i] >= target_index)
                return true;
            else
                return false;
        }

        if(dp[i][target_index]!=-1)
            return dp[i][target_index];

        if(i>=2){

        bool include = false;

        if(i+nums[i] >=target_index){
            include = true && solve(i-1, nums,i,dp);
        }

        bool exclude = solve(i-1,nums,target_index,dp);

        return dp[i][target_index] = include || exclude;
        }
    return dp[i][target_index] = false;
    }

    bool canJump(vector<int>& nums) {

    //    int n = nums.size();
    //    if(n==1)
    //     return true;
    //     vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    //    return solve(n-2, nums,n-1,dp);
        int maxReach = 0;
        for(int i = 0; i<nums.size();i++){
            if(maxReach < i) return false;
            maxReach = max(maxReach, i+nums[i]);
        }
        return true;
    }