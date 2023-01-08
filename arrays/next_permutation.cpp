#include <iostream>
#include <vector>
using namespace std;


void nextPermutation(vector<int>& nums) {
        
    int i = nums.size()-2;

    //Step 1, Find a[i]<a[i+1]
    while (i>=0 && nums[i]>=nums[i+1])
        i--;
    
    if(i>=0){
        int j=nums.size()-1;
        //Step 2. Find a[j]>a[i]
        while (nums[j]<=nums[i])j--;
        swap(nums[i],nums[j]);
    }
        int k = i+1,j=nums.size()-1;
        while (k<j)
        {
            swap(nums[k],nums[j]);
            k++;
            j--;
        }

     for (auto i : nums)
    {
        cout<<i<<" ";
    }

}

int main(){ 

    vector<int> nums = {1,1,3,5};

    //Optimal Solution
    nextPermutation(nums);

    //Bruteforce Naive Approach

    // if(nums[i]<=nums[j] && nums[j]<=nums[k]){
    //     swap(nums[j],nums[k]);
    // }else if (nums[i] <= nums[j] && nums[j]>=nums[k]){
    //     swap(nums[i],nums[j]);
    //     swap(nums[i],nums[k]);
    // }else if ((nums[j]<=nums[i] && nums[j]<=nums[k]) && nums[i]<=nums[k]){
    //     swap(nums[j],nums[k]);
    // }else if((nums[j]>=nums[i] && nums[j]>=nums[k]) && nums[i]>=nums[k]){
    //     swap(nums[i],nums[j]);
    //     swap(nums[j],nums[k]);
    // }else if((nums[j]<=nums[i] && nums[j] <=nums[k]) && nums[i]>=nums[k]){
    //     swap(nums[j],nums[k]);
    // }else{
    //     swap(nums[k],nums[i]);
    // }
    return 0;
}