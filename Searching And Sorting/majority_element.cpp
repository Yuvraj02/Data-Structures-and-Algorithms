#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// int firstOccurence(vector<int>&,int);
// int lastOccurence(vector<int>&,int);

int majorityElement(vector<int>& A){

    int count = 0,majority_element = 0;
    for(int i = 0;i<A.size();i++){
        if(count==0) majority_element=A[i];

        if(A[i]==majority_element)
            count++;
        else
            count--;

    }
    return majority_element;
}

int main(){

    vector<int> A = {2,2,1,1,1,2,2};
 //   cout<<firstOccurence(A,2);
    cout<<majorityElement(A);

    return 0;
}

// int majorityElement(vector<int>& A){

//     sort(A.begin(),A.end());
//     int l = 0,r=0,max_element = A[0],max_element_count=0;

//     while (l<A.size())
//     {
//         int key = A[l];
//         l = firstOccurence(A,key);
//         r = lastOccurence(A,key);

//         if(r-l+1 > max_element_count){
//             max_element_count = r-l+1;
//             max_element = key;
//         } 
//         l=r+1; 
//     }
//     return max_element;

// }

// int firstOccurence(vector<int>& A, int key){

//     int start = 0,end = A.size()-1,mid = start + (end-start)/2;
//     int firstIndex;
//     while (start<=end)
//     {
//         if(A[mid]==key){
//             firstIndex= mid;
//             end = mid-1;
//         }else if(A[mid]>key){
//             end = mid-1;
//         }else{
//             start = mid+1;
//         }
//         mid = start+(end-start)/2;
//     }
//     return mid;
// }

// int lastOccurence(vector<int>&A, int key){
//     int start = 0, end = A.size()-1, mid=start + (end-start)/2;

//     int lastIndex;

//     while (start<=end)
//     {
//         if(A[mid]==key){
//             lastIndex=mid;
//             start = mid+1;
//         }else if(A[mid]>key){
//             end = mid-1;
//         }else{
//             start = mid+1;
//         }
//         mid = start + (end-start)/2;
//     }
    
//     return mid;
// }