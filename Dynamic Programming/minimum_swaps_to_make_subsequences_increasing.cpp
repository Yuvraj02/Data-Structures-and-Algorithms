#include <iostream>
#include <vector>

using namespace std;

int solveRec(int index, vector<int>&nums1, vector<int> &nums2,bool swapped){

    if(index>=nums1.size())
        return 0;

    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];

    if(swapped)
        swap(prev1,prev2);
    
    int ans = INT32_MAX;
    //No swap
    if(nums1[index] > prev1 && nums2[index] > prev2)
        ans = solveRec(index+1,nums1,nums2,0);

    //Swap
    if(nums2[index] > prev1 && nums1[index] > prev2)
        ans = min(ans, 1 + solveRec(index+1, nums1,nums2,1));

    return ans;
}

int solveMem(int index, vector<int>& nums1, vector<int>& nums2, bool swapped,vector<vector<int>>& dp){
        if(index >= nums1.size())
            return 0;

        if(dp[index][swapped] != -1)
            return dp[index][swapped];

        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(swapped)
            swap(prev1,prev2);

        int ans = INT32_MAX;
        //No swap
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solveMem(index+1, nums1,nums2,0,dp);

        //Swap
        if(nums2[index] > prev1 && nums1[index] > prev2)
            ans = min(ans, 1 + solveMem(index+1, nums1,nums2, 1,dp));

        dp[index][swapped] = ans;
        return dp[index][swapped];
}

int solveTab(vector<int>& nums1, vector<int>& nums2){

nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    
    int n = nums1.size();
    vector<vector<int>> dp(n+1,vector<int>(2, 0));

    for(int index = n-1 ;index >= 1; index--){
            for(int swapped = 0; swapped<2; swapped++){
                    
                    int prev1 = nums1[index-1];
                    int prev2 = nums2[index-1];

                    if(swapped)
                        swap(prev1,prev2);
        
            int ans = INT32_MAX;
            //No swap
            if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = dp[index+1][0];

        //Swap
        if(nums2[index] > prev1 && nums1[index] > prev2)
            ans = min(ans, 1 + dp[index+1][1]);

        dp[index][swapped] = ans;
                        
            }
    }

    return dp[1][0];
    
}

int spaceOptimized(vector<int>&nums1, vector<int>&nums2){

    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);

    

    int n = nums1.size();
    //vector<vector<int>> dp(n+1,vector<int>(2, 0));

    vector<int> curr(2,0);
    vector<int> next(2,0);

    for(int index = n-1 ;index >= 1; index--){
            for(int swapped = 0; swapped<2; swapped++){
                    
                    int prev1 = nums1[index-1];
                    int prev2 = nums2[index-1];

                    if(swapped)
                        swap(prev1,prev2);
        
            int ans = INT32_MAX;
            //No swap
            if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = next[0];

        //Swap
        if(nums2[index] > prev1 && nums1[index] > prev2)
            ans = min(ans, 1 + next[1]);

        curr[swapped] = ans;
                        
            }
            next = curr;
    }

    return next[0];
    

}

int minSwap(vector<int>& nums1, vector<int>& nums2) {

    
    //return solveMem(1,nums1,nums2,0,dp);
    return spaceOptimized(nums1,nums2);
}


int main(){

    vector<int> A = {1,3,5,4};
    vector<int> B = {1,2,3,7};
    cout<<minSwap(A,B);
    return 0;
}