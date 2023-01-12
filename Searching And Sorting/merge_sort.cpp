#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>&arr, int start,int end){

    int mid = start + (end-start)/2;
    int firstArrayLength = mid-start+1;
    int secondArrayLength = end-mid;

    vector<int>A (firstArrayLength);
    vector<int>B(secondArrayLength);

    //Copy the contents of arr to A and B
    //Copying to A first
    int indexOfMainArray = start;
    for (int i = 0; i < firstArrayLength; i++){
        A[i]=arr[indexOfMainArray++];
    }
        
    //Copying to B then
    indexOfMainArray = mid+1;
    for (int i = 0; i < secondArrayLength; i++)
    {
        B[i]=arr[indexOfMainArray++];
    }

    //Perform merge Two Sorted Arrays
    //Pointer to A
    int i = 0;
    //Pointer to B
    int j = 0;
    //Pointer to main Array
    int k = start;

    //Start copying smaller element to main arr
    while (i<A.size() && j<B.size())
    {
        if(A[i]<=B[j]){
            arr[k]=A[i];
            i++;
        }else{
            arr[k]=B[j];
            j++;
        }
        k++;
    }
    //Copy rest of the values from A
    while (i<A.size()){
        arr[k]=A[i];
        k++;
        i++;
    }
        
    //Copy rest of the values from B
    while (j<B.size()){
        arr[k]=B[j];
        k++;
        j++;
    }

}


int mergeSort(vector<int> &A, int start, int end){
    
    if(start>=end){
        return;
    }

    int mid = start + (end-start)/2;

    mergeSort(A,start,mid);
    mergeSort(A,mid+1,end);

    merge(A,start,end);

}



int main(){

    vector<int> A = {2,1,4,7,5,9,3};

    mergeSort(A,0,A.size()-1);    

    for (auto i : A)
    {
        cout<<i<<" ";
    }
    
    return 0;
}