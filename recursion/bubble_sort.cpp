#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &A,int i){

    if(i==A.size()-1)
        return;

    for (int j=0; j < A.size()-1; j++)
    {
        if(A[j]>A[j+1])
            swap(A[j],A[j+1]);
    }

    bubbleSort(A,i+1);
    
}

int main(){

    vector<int> A = {2,4,1,3,6,9,11};

    bubbleSort(A,0);

    for(auto i : A){
        cout<<i<<" ";
    }

    return 0;
}