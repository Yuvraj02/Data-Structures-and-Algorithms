#include <iostream>

using namespace std;

int main(){
    int n = 2;
    int arr[n] = {0,1};

    int *output = new int[n];

    int prefix = 1,postfix = 1;

    //Insert prefix first, then multiplt by that number
    for(int i=0;i<n;i++){
        output[i] = prefix;
        prefix*=arr[i];
    }

    //Traverse from the back and get postfix first

    for(int i = n-1;i>=0;i--){
        output[i] *= postfix;
        postfix *= arr[i];
    }

    for(int i = 0;i<n;i++){
        cout<<output[i]<<" ";
    }

}