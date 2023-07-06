 #include<iostream>
 #include<vector>

 using namespace std;


 int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0,right = 0,min_size = INT32_MAX,sum=0;

        for(right;right<nums.size();right++){
            
            sum+=nums[right];
           // cout<<sum<<" ";
            while(sum>=target){
                
                min_size = min(min_size, right-left+1);
                sum -= nums[left];
                left++;
            }
            // cout<<sum<<" ";
             //if(sum>=target)
        }
        return min_size == INT32_MAX? 0 : min_size;
}

int main(){
    
    vector<int> a = {2,3,1,2,4,3};
    int target = 7;

    cout<<minSubArrayLen(target,a);
    return 0;
}