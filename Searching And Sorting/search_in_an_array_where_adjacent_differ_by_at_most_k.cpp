#include <iostream>

using namespace std;


int search(int arr[], int n, int x, int k){

    for(int i=0;i<n;i++){
        if(arr[i]==x)
            return i;
    }
return -1;
}

int main(){

    int arr[] = {2,3,5,6,6,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x=6;
    int k = 1;

    cout<<search(arr,n,x,k)<<endl;

    return 0;
}