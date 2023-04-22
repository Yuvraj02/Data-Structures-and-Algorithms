#include <iostream>
#include <vector>

using namespace std;

int solveMem(int, vector<int>&, vector<int>&);
int solveTab(vector<int>&);


int solveTabOptimized(vector<int> &nums){
    int n = nums.size();
    
    //case 1
    int curr1 = 0,next1=0,prev1=0;
    for(int index = n-2;index>=0;index--){
        int include = nums[index] + next1;
        int exclude = curr1;
        prev1 = max(include,exclude);

        next1=curr1;
        curr1=prev1;
    }
    int case1 = curr1;

    //case 2
    int curr2 = 0,next2=0,prev2=0;
    for(int index = n-1; index>=1;index--){
            int include = nums[index] + next2;
            int exclude = curr2;
            prev2 = max(include,exclude);
            
            next2 = curr2;
            curr2 = prev2;
    }
    int case2 = curr2;

    return max(case1,case2);
    }

    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if(n==1)
            return nums[0];

        /* For Memoization

            vector<int> dp1(n+1,-1),dp2(n+1,-1);

            //Rob first house and leave last house
            int case1 = solveMem(0,nums,n-2,dp1);

            //Rob last house and leave first house
            int case2 = solveMem(1,nums,n-1,dp2);

        return max(case1,case2);
        */

       return solveTabOptimized(nums);
    }
int main(){
    
    vector<int> arr = {1,2,3,1};

    cout<<rob(arr);
    return 0;

}

int solveMem(int index, vector<int> &nums, int n, vector<int>&dp){
        if(index>n)
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];

        int include = nums[index] + solveMem(index+2, nums,n,dp);

        int exclude = solveMem(index+1,nums,n,dp);

        return dp[index] = max(include,exclude);

    }

    int solveTab(vector<int> &nums){
        int n = nums.size();

        vector<int> dp1(n+2, 0);
        vector<int> dp2(n+2, 0);

        //case 1
        for(int index = n-2;index>=0;index--){
            int include = nums[index] + dp1[index+2];
            int exclude = dp1[index+1];
            dp1[index] = max(include,exclude);
        }
    int case1 = dp1[0];

    //case 2

    for(int index = n-1; index>=1;index--){
            int include = nums[index] + dp2[index+2];
            int exclude = dp2[index+1];

            dp2[index] = max(include,exclude);
    }
    int case2 = dp2[1];

    return max(case1,case2);

    }

