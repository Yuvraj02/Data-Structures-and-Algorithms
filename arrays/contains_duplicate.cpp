#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>
using namespace std;

    bool containsDuplicate(vector<int> nums){
        unordered_set<int> s;

        for(int i=0;i<nums.size();i++){
                auto it = s.find(nums[i]);
                if(it!=s.end())
                    return true;
                s.insert(nums[i]);
        }
        return false;
    }
int main(){

    vector<int> A = {1,2,3,1};

    cout<<boolalpha<<containsDuplicate(A);

    return 0;
}