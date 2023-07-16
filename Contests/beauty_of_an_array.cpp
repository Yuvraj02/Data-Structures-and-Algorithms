#include <iostream>
#include <vector>
#include <utility>

using namespace std;

 int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();

    bool check = true;
    for(int i = 1; i<nums.size();i++){
        if(nums[i]!=nums[i-1]){
            check = false;
            break;
        }
    }
    if(check)
        return nums.size();

    vector<pair<int,int>> intervals;

    for(int i = 0; i<nums.size();i++){
        intervals.push_back({nums[i]-k,nums[i]+k});
    }

    int max_overlapping = INT32_MAX;
    int count = 1;
    for(int i = 0; i<intervals.size();i++){
        count = 0;
        for(int j = 0; j<intervals.size();j++){

            pair<int,int> i1 = intervals[i];
            pair<int,int> i2 = intervals[j];
            if(i1.first <= i2.second && i1.second >= i2.first){
                count++;
            }
        }
        max_overlapping = min(count,max_overlapping);
    }
    return max_overlapping;
}

int main(){

    vector<int> nums = {1,6,4,2};
    int k = 2;
    cout<<maximumBeauty(nums,k);
    return 0;
}