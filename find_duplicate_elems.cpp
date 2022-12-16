#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){

    vector<int> nums = {3,1,3,4,2};

    unordered_set<int> s;

    //Bruteforce approach

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = 0; j < nums.size(); j++)
    //     {
    //         if(i==j)
    //             continue;
    //         if(nums[i]==nums[j]){
    //             cout<<nums[i];
    //             break;
    //         }
    //     }
        
    // }
    
    //Optimized approach (Using set)
        auto it = s.begin();

        for (int i = 0; i < nums.size(); i++)
        {
            it = s.find(nums[i]);
            if(it != s.end())
                return *it;

            s.insert(nums[i]);    
        }
        


    return 0;
}