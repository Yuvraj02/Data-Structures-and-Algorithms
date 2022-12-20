#include <iostream>

using namespace std;

int main(){

    int arr[] = {0,1,1,0,0,1,1,0,1,0};

    int n = sizeof(arr)/sizeof(int);

    //int i=0,j=0,k=n-1;
//Bruteforce---
 
    // while (i<j)
    // {
    //     if(arr[i]==0 && arr[j]==0){
    //         i++;
    //     }else if(arr[i]==0 && arr[j]==1){
    //         i++;
    //     }else if(arr[i]==0 && arr[j]==2){
    //         i++;
    //         j--;
    //     }else if(arr[i]==1 && arr[j]==0){
    //         swap(arr[i],arr[j]);
    //         i++;
    //     }else if(arr[i]==1 && arr[j]==1){
    //         i++;
    //     }else if(arr[i]==1 && arr[j]==2){
    //         i++;
    //         j--;
    //     }else if (arr[i]==2 && arr[j]==0){
    //         swap(arr[i],arr[j]);
    //         i++;
    //         j--;
    //     }else if (arr[i]==2 && arr[j]==1){
    //         swap(arr[i],arr[j]);
    //         i++;
    //         j--;
    //     }else if (arr[i]==2 && arr[j]==2){
    //         i++;
    //     }

    // }


    int low=0,mid=0,high=n-1;
    while (mid<=high)
    {
        if(arr[low]==0 && arr[mid]==0){
            low++;
            mid++;
        }else if(arr[mid]==1){
            mid++;
        }else if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }else if(arr[mid]==2){
            swap(arr[high],arr[mid]);
            high--;
        }

    }
    

   for (auto i : arr)
   {
    cout<<i<<" ";
   }
   

    return 0;
}