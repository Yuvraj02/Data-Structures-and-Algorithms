#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main(){

    vector<int> A = {5,20,3,2,5,80};
    int x = 90;

    //Best Approach
    //User unordered_set
    unordered_set<int> sset;
    
    for (int i = 0; i < A.size(); i++)
    {
            auto it = sset.find(A[i]);
            if(it!=sset.end()){
                cout<<"YES";
                break;
            }else{
                sset.insert(A[i]+x);
            }
    }
    

 return 0;
}


    //Optimized Approach
    //Sort the array
    //Perform binary search on (A[i]+x) from i+1 value

// bool find(vector<int> A, int key,int startIndex){

// int start = startIndex, end = A.size(),mid = start + (end-start)/2;

// while (start<=end)
// {
//     if(A[mid]==key){
//         return true;
//     }else if(A[mid]>key){
//         end=mid-1;
//     }else{
//         start = mid+1;
//     }
//     mid = start + (end-start)/2;
// }
// return false;
// }

// bool findPair(vector<int> A, int x){
//     sort(A.begin(),A.end());
 
//     for (int i = 0; i < A.size(); i++)
//     {
//         int key = A[i]+x;
//         if(find(A,key,i+1)){
//             return true;
//         }
//     }
//     return false;
// }




    //Bruteforce Approach----------------------
    // bool isPair = false;
    // for (int i = 0; i < A.size(); i++)
    // {
    //     for (int j = 0; j < A.size(); j++)
    //     {
    //         if(abs(A[i]-A[j])==x){
    //             cout<<A[i]<<", "<<A[j]<<endl;
    //             isPair=true;
    //             break;
    //         }
    //     }
    //     if(isPair)
    //         break;
    // }
 