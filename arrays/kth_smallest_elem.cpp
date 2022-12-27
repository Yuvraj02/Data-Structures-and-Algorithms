#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int partition(int arr[], int left, int right){

    int pivot = arr[right];
    int i = left;

    for (int j = i; j <= right-1; j++)
    {
        if(arr[j]<=pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[right]);
    return i;
   
}

int kthSmallest(int arr[], int l, int r, int K)
{
        int position = partition(arr,l,r);

        if(position == K-1){
            return arr[position];
        }else if(position < K-1){
            //Search in right subarray
            return kthSmallest(arr,position+1,r,K);
        }else{
            //search in left subarray
            return kthSmallest(arr,l,position-1,K);
        }

    return -1;
}


int main(){

    int arr[] = {7,10,4,3,20,15};
    int n = sizeof(arr)/sizeof(int);
   cout<<kthSmallest(arr,0,n-1,3);
    

    return 0;
}