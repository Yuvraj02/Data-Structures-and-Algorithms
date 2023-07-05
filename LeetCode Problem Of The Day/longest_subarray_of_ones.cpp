 #include <iostream>
 #include <vector>

 using namespace std;
 
 int longestSubarray(vector<int>& nums) {

        int left = 0,right=0,zero_count=0,max_ones=0;
    
    //Using Sliding Window
        for(right; right<nums.size();right++){

            if(nums[right]==0)
                zero_count++;

            while(zero_count > 1){

                if(nums[left]==0)
                    zero_count--;
                left++;
            }
            if(zero_count)
                max_ones = max(max_ones, (right-left+1)-zero_count);
            else
                max_ones = max(max_ones,(right-left+1)-1);
        }
    return max_ones;
}

int main(){

    vector<int> nums = {0,1,1,1,0,1,1,0,1};

    cout<<longestSubarray(nums);

    return 0;
}