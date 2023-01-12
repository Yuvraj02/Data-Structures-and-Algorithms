#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& A, int start, int end){

    int pivot = A[end];
    int i = start;
    for (int j = start; j <= end; j++)
    {
        if(A[j]<pivot){
            swap(A[i],A[j]);
            i++;
        }
    }
    swap(A[i],A[end]);

return i;
}

void quickSort(vector<int>&A, int start, int end){

    if(start>=end){
        return;
    }

    int pi = partition(A,start,end);
   
    quickSort(A,start,pi-1);
    quickSort(A,pi+1,end);  

}

int main(){
    vector<int> A = {2,1,7,7,4,4,9,3,3};

    quickSort(A,0,A.size()-1);
    for (auto i : A)
    {
        cout<<i<<" ";
    }
    

    return 0;
}