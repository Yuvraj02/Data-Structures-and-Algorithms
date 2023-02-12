#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long countFairPairs(vector<int>& nums, int lower, int upper) {
    
    long long count=0;
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<nums.size();i++){

        int left = i+1, right=nums.size()-1;

        while (left<right && nums[left]+nums[i]<lower) left++;
        while (left<right && nums[right]+nums[i]>upper) right--;

        count += right-left+1;

    }

    return count-3;
}

int main(){

    vector<int> nums = {1,7,9,2,5};
    cout<<countFairPairs(nums,11,11);

    return 0;
}