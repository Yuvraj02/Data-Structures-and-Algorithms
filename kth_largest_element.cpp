#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& A, int low, int high){

    int pivot = A[high];
    int i = low;

    for (int j = i; j < high; j++)
    {
        if(A[j]<=pivot){
            swap(A[i],A[j]);
            i++;
        }
    }
    swap(A[i],A[high]);

    return i;
}

int findKthLargestElement(vector<int> &A, int low, int high,int k){

    //Find position of the pivot
    int position = partition(A,low,high);

    //If position of pivot is equal to position at length-k then return the pivot element
    if(position == A.size()-k){
        return A[position];
    //If pivot's position is less than k then search in right half
    }else if(position < A.size()-k){
        return findKthLargestElement(A,position+1,high,k);
    //If pivot's position is more than k then search in left half
    }else{
        return findKthLargestElement(A,low,position-1,k);
    }
}

int main(){

    vector<int> A = {3,2,3,1,2,4,5,5,6};

    cout<<findKthLargestElement(A,0,A.size()-1,2)<<endl;
    return 0;
}
