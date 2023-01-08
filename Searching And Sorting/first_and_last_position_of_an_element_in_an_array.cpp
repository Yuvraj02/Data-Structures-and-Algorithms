#include <iostream>
#include <vector>

using namespace std;

int findFirstOccurence(vector<int> &A,int key)
{

    int start = 0;
    int end = A.size() - 1;
    int mid;
    int ans= -1;
    while (start <= end)
    {
        mid = (start+end)/2;

        if(A[mid]==key){
            ans = mid;
            end = mid - 1;
        }else if(key<A[mid]){
            //Search in left half
            end = mid-1;
        }else{
            //Search in first half
            start = mid+1;
        }

    }
    return ans;
}

int findLastOccurence(vector<int>&A, int key){

    int start = 0,end=A.size()-1,mid = start + (start+end)/2;
    int ans= -1;

    while (start<=end)
    {
        if(A[mid]==key){
            ans = mid;
            start = mid+1;
        }else if(key<A[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }

    return ans;
}

int main()
{

    vector<int> A = {0, 5, 5, 6, 6, 6};
    cout<<findFirstOccurence(A,5)<<","<<findLastOccurence(A,5);
    return 0;
}