#include <iostream>
#include <vector>

using namespace std;

int findFirstOccurence(vector<int>& A, int key){

    int start = 0, end = A.size()-1, mid = start + (end-start)/2;
    int ans = -1;
    while (start<=end)
    {
       if(key==A[mid]){
            ans = mid;
            end = mid-1;
       } else if(key < A[mid]){
            end = mid-1;
       }else{
        start = mid+1;
       }
       mid = start + (end-start)/2;
    }
    return ans;
}

int findLastOccurence(vector<int>& A, int key){

    int start = 0, end = A.size()-1, mid = start + (end-start)/2;
    int ans = -1;
    while (start<=end)
    {
       if(key==A[mid]){
            ans = mid;
            start = mid+1;
       } else if(key < A[mid]){
            end = mid-1;
       }else{
        start = mid+1;
       }
       mid = start + (end-start)/2;
    }
    return ans;
}

int main(){

    vector<int> A = {1,2,2,2,2,2,2,3,3,3,5};
    cout<<"Frequency is : "<<findLastOccurence(A,2)-findFirstOccurence(A,2)+1<<endl;
    
}