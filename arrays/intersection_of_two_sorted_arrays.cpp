#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> arr1 = {1,2,2,2,3,4};
    vector<int> arr2 = {2,2,3,3};
    vector<int> finalVec;

    //Bruteforce Approach

    // for (int i = 0; i < arr1.size(); i++)
    // {
    //         for (int j = 0; j < arr2.size(); j++)
    //         {
    //             if(arr1[i]==arr2[j]){
    //                 finalVec.push_back(arr2[j]);
    //                 arr2[j] = INT32_MIN;
    //                 break;
    //             }
    //         }

    // }

    
    //Optimized Approach

    int i=0,j=0;

    while (i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<arr2[j])
            i++;
        if(arr2[j]<arr1[i])
            j++;
        if(arr1[i]==arr2[j]){
            finalVec.push_back(arr2[j]);
            i++;
            j++;
        }
        
    }
    return 0;
}