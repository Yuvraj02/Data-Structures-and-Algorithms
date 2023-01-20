#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &A, int i){

    if(i==A.size()-1)
        return ;

    int minimumVal = A[i],minIndex=i;
    for(int j=i+1; j<A.size();j++){
        if(A[j]<minimumVal){
            minimumVal = A[j];
            minIndex = j;
        }
    }
    swap(A[i],A[minIndex]);

    selectionSort(A,i+1);

}

int main(){

    vector<int> A = {2,8,1,3,6,5,7,9,4};

    selectionSort(A,0);

    for(auto i : A){
        cout<<i<<" ";
    }

    return 0;
}