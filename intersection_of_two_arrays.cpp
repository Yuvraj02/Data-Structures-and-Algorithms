#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int> nums1,vector<int> nums2){

vector<int> C;
int big,small;

    if(nums1.size()>nums2.size()){
        big = nums1.size();
        small = nums2.size();
    }else{
        big = nums1.size();
        small = nums2.size();
    }
    
    for (int i = 0; i < small; i++)
    {
        for(int j = 0; j <big;j++){
                if(nums1[i]==nums2[j]){
                auto it = find(C.begin(),C.end(),nums2[j]);
                if(it != C.end()){
                    continue;
                }else{
                    C.push_back(nums2[j]);
                }
                }
        }

    }

    return C;

}

int main(){

    vector<int> A = {4,9,5};
    vector<int> B = {9,4,9,8,4,2};
    
    

    for (auto i : intersection(A,B))
    {
        cout<<i<<endl;
    }
    
    

    return 0;
}