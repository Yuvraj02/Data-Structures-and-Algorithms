#include <iostream>
#include <vector>

using namespace std;


void partition(vector<int> A,int i,int j){

    if(j==A.size()-1)

    int pivot = A[A.size()-1];

    int i=0,j=A.size()-1;

    // while (i<=j)
    // {
    //     while (i<pivot)
    //         i++;
        
    //     while (j>=pivot)
    //         j--;

    //     if(i<=j)
    //         swap(A[i],A[j]);
    // }

    swap(A[j],A[A.size()-1]);

    partition(A,j,A.size()-1);

    for (auto i : A)
    {
        cout<<i<<" ";
    }
    

}

int main(){

    vector<int>  nums = {3,2,1,5,6,4};
    int k = 2;

    partition(nums);

    return 0;
}