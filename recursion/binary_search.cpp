#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> A, int start, int end, int key){
    
    int mid = start+(end-start)/2;

    if(start>end){
        //Element not found
        return -1;
    }
    if(A[mid]==key)
        return mid;
    if(key<A[mid])
        return binarySearch(A,start,mid-1,key);
    if(key>A[mid])
        return binarySearch(A,mid+1,end,key);

    return -1;    
}


int main(){
    
    vector<int> A = {1,4,6,8,10,12,14};
    int key = 12;
    cout<<binarySearch(A,0,A.size()-1,key);

    return 0;
}