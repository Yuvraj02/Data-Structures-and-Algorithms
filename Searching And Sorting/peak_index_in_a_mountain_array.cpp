#include <iostream>
#include <vector>

using namespace std;

int findPeak(vector<int> A){

    int start = 0, end = A.size()-1,mid = start + (end-start)/2;

    while (start<=end)
    {
        if(A[mid]>A[mid-1] && A[mid]>A[mid+1]){
            return A[mid];
            //Search in increasing part
        }else if(A[mid]<A[mid+1]){
            start=mid+1;
        }else{
            end=mid;
        }

        mid = start+(end-start)/2;

    }
return -1;
}

int main(){

vector<int> A = {24,69,100,99,79,78,67,36,26,19};

cout<<findPeak(A);

}