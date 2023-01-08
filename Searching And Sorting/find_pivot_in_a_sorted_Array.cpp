//Same as finding minimum in a sorted array
#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> A){

    int start = 0,end= A.size()-1,mid = start + (end-start)/2;

    if(A[start]<A[end]){
        return A[start];
    }

    while (start<=end)
    {
        if(A[mid+1]<A[mid]){
            return A[mid+1];
        }else if(A[mid-1]>A[mid]){
            return A[mid];
        }else if (A[mid]>A[end]){//Search in unsorted part
            start=mid+1;
        }else{
            end=mid-1;
        }
        mid = start + (end-start)/2;
    }
    
return -1;
}


int main(){

    vector<int> A = {1};

    cout<<findPivot(A);

    return 0;
}