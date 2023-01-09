#include <iostream>
#include <vector>

using namespace std;

bool isPossibleSolution(vector<int> A,int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if(pageSum+A[i]<=mid){
            pageSum+=A[i];
        }else{
            studentCount++;
            if(studentCount > m || A[i]>mid){
                return false;
            }
            pageSum = A[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> A, int n, int m){

    int start = 0,end=0;
    int ans= -1;
    for (int i = 0; i < n; i++)
    {
        end+=A[i];
    }
    
    int mid = start + (end-start)/2;

    while (start<=end)
    {
        if(isPossibleSolution(A,n,m,mid)){
            ans = mid;
            end = mid-1;
        }else{
            start=mid+1;
        }        
        mid = start+(end-start)/2;
    }
return ans;
}

int main(){

    vector<int> A = {12,34,67,90};
    int m = 2;

    cout<<allocateBooks(A,A.size(),m);

    return 0;
}