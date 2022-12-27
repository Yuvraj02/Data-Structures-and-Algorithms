#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){

    vector<int> nums = {1};
    vector<int> finalVec;   

    for (int i = 0; i < nums.size(); i++)
    {
        //Flip the contents of index value
            if(nums[abs(nums[i])-1] < 0){
                finalVec.push_back(abs(nums[i]));
            }
          
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
    }
    
    for (auto i : finalVec)
    {
        cout<<i<<" ";
    }
    

    return 0;
}