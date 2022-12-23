#include <iostream>
#include <vector>

using namespace std;


int findMin(vector<int> A){

    int start=0;
    int end=A.size()-1;

    int mid,output;
    if(A[start] <= A[end])
        return A[0];
    while (start<=end)
    {
        mid = (start+end)/2;

        if (A[mid]>A[mid+1]){
            return A[mid+1]; 
        }else if(A[mid]<A[mid-1]){
            return A[mid];

            //Go to Right side if left side is sorted 
        }else if (A[start]<=A[mid]){
            start = mid+1;
            //Go to left side if right side is sorted
        }else if (A[mid]<=A[end]){
            end=mid-1;
        }
       
    }
    return -1;
}

int main(){

    vector<int> A = {3,4,5,1,2};
                 //   {1,2,3,4,5};
                    //{5,4,3,2,1}
                    
    cout<<findMin(A);
    return 0;
}