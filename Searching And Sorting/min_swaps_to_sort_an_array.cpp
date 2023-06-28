#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){ 

    //We will approach this problem in reverse
    /*
        For example, we will sort the array first, with it's index position,
        then check which index is at incorrect position and count such indices.
        If the indices are in correct position then we simply move forward
    */

    vector<int> nums = {10,19,6,3,5};
    //Step 1 : Create a pair of Values with their current indices
    
    vector<pair<int,int>> p;

    for(int i = 0 ; i<nums.size();i++){
        //Store values and indices
        p.push_back({nums[i], i});
    }

    //Sort the pairs w.r.t the values 
    sort(p.begin(),p.end());

    //Now keep count of those values which are not in correct index
    int count = 0;
    for(int i = 0; i<p.size();i++){
        //If the values are at incorrect position
        //Then swap it with it's correct position 
        if(p[i].second!=i){
            swap(p[i],p[p[i].second]);
            count++;
            i--;
        }
    }

    cout<<count<<endl;

    return 0;
}