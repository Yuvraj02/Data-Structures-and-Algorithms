#include <iostream>
#include <vector>

using namespace std;

 int solve(vector<int> &nums, int target,vector<int> &dp){

        if(target==0)
            return 1;
        
        if(target<0)
            return 0;
        
        if(dp[target]!=-1)
            return dp[target];

        int ans = 0;
        
        for(int i = 0; i<nums.size();i++){
            ans += solve(nums,target-nums[i],dp);
        }
        return dp[target] = ans;
    }

    int solveTab(vector<int>& nums, int target){

        vector<int> dp (target+1, 0);

        dp[0] = 1;

        for(int k = 1; k <=target; k++){
            
            long long ans = 0;
            for(int i = 0; i<nums.size();i++){
        
                if(k-nums[i] >=0)
                    ans+=dp[k-nums[i]];
            }
            dp[k] = ans;
        }

        return dp[target];

    }

    int combinationSum4(vector<int>& nums, int target) {
        
        // int n = nums.size();
        vector<int> dp (target+1, -1);

        //int ans = solve(nums,target,dp);
        int ans = solveTab(nums,target);
        return ans;
    }

    int main(){
        vector<int> nums = {1,2,3};
        int target = 4;
        cout<<combinationSum4(nums,target);
        return 0;
    }