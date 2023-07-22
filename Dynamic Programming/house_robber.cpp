#include <iostream>
#include <vector>

using namespace std;


//Bottom Up Approach
    int solve(int i, vector<int> &nums,vector<int> &dp){

        if(i>=nums.size())
            return 0;

        if(dp[i]!=-1)
            return dp[i];
        
        //1. Include
        int include = nums[i] + solve(i+2,nums,dp);

        //2. Exclude
        int exclude = solve(i+1,nums,dp);

        return dp[i] = max(include,exclude);
    }

    //Top Down Approach
    int solveTab(vector<int> &nums){

        int n = nums.size();
        vector<int> dp(n+2, 0);

        for(int i = n-1; i>=0;i--){
            int include = nums[i] + dp[i+2];

            int exclude = dp[i+1];

            dp[i] = max(include,exclude);
        }
        return dp[0];
    }

    int spaceOptim(vector<int> &nums){

        int n = nums.size();

       int next2 = 0;
       int curr = 0;

        for(int i = n-1; i>=0;i--){
            int include = nums[i] + next2;
            int exclude = curr;
            next2 = curr;
            curr = max(include,exclude);
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        //int n = nums.size();
        //vector<int> dp (n+1, -1);
        //return solve(0,nums,dp);
        //return solveTab(nums);
        return spaceOptim(nums);
    }
    