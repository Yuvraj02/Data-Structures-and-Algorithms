#include <iostream>
#include <vector>
using namespace std;


void quickSort(vector<int> A){

    int pivot = A[0];

    //partition the elements until the pivot is in center
    
    int i = 1,j=A.size()-1;
    while (i<=j)
    {
        
        while (A[i]<=pivot)
            i++;

        while (A[j]>pivot)
            j--;
        
        if(i<j)
            swap(A[i],A[j]);
    }

    swap(A[j],A[0]);

    for (auto i : A)
    {
        cout<<i<<" ";
    }
    

}

int main(){

    vector<int> A = {3,2,1,5,6,4};

    quickSort(A);

    return 0;
}