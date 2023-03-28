#include <iostream>
#include <vector>

using namespace std;



int findWays(vector<int> &num, int tar)
{
    vector<int> dp(tar+1,0);

   // int ans = solve(num,tar,dp);
    dp[0] = 1;
    for(int i=1; i<=tar;i++){
        for(int j = 0; j<num.size();j++)
            if(i-num[j]>=0)
                dp[i] += dp[i-num[j]];
    }
    return dp[tar];
}

int main(){
    vector<int> num = {12,1,3};
    int target = 4;
    
    cout<<findWays(num,target);
    return 0;
}

//DP Solution:
// int solve(vector<int> &nums, int tar,vector<int> &dp){

// // Write your code here.
//     if(tar==0){
//         return 1;
//     }

//     if(tar<0)
//         return 0; 

//     if(dp[tar]!=0)
//         return dp[tar];
    
//     for(int i=0;i<nums.size();i++){
//         dp[tar] += solve(nums,tar-nums[i],dp);
//     }

//     return dp[tar];
// }
