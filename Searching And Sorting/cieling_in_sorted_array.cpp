#include <iostream>
#include <vector>
using namespace std;


int ceilingInSortedArray(int n, int x, vector<int> &A){
    // Write your code here.
    int start = 0,end=n-1,mid= start + (end-start)/2;
     int ans = -1;
    while(start<=end){
        if(A[mid]>=x){
            ans = mid;
            end = mid-1;
        }else if(A[mid]<x){
            start = mid+1;
        }
        mid = start+ (end-start)/2;
    }
    
    return A[ans];
}


int main(){

    vector<int> A = {1,1,3,4,4,5};
    int x = 2;
    int n = A.size();
    cout<<ceilingInSortedArray(n,x,A);

    return 0;
}