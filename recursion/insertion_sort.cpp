#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &A, int i){

    if(i==A.size())
        return;
    
    int temp = A[i];
    int j = i-1;
    while (A[j]>temp && j>=0)
    {
        //Shift everything to right
        A[j+1]=A[j];
        j--;
    }
    
    A[j+1]=temp;
    insertionSort(A,i+1);
}

int main(){
    
    vector<int> A = {2,8,1,3,6,5,7,3,9,4};
    insertionSort(A,0);

    for(auto i: A){
        cout<<i<<" ";
    }

    return 0;
}