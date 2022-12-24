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
    // If k is smaller than number of elements in array
    if (K > 0 && K <= r - l + 1) {

        // Partition the array around last element and get
        // position of pivot element in sorted array
        int pos = partition(arr, l, r);

        // If position is same as k
        if (pos - l == K - 1)
            return arr[pos];
        if (pos - l > K - 1) // If position is more, recur
                             // for left subarray
            return kthSmallest(arr, l, pos - 1, K);

        // Else recur for right subarray
        return kthSmallest(arr, pos + 1, r,
                           K - pos + l - 1);
    }
    return -1;
}


int main(){

    int arr[] = {7,10,4,3,20,15};
    int n = sizeof(arr)/sizeof(int);
   cout<<kthSmallest(arr,0,n-1,2);
    

    return 0;
}