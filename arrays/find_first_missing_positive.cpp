#include <iostream>
#include <vector>

using namespace std;

int findFirstMissingPositive(vector<int> &arr, int n){
 //Step 1 : Find if there's 1 in the array, if not then return 1
    bool is1present = false;

    for(int i = 0; i<n;i++){
        if(arr[i]==1){
            is1present = true;
            break;
        }
    }

    if(is1present==false)
        return 1;

  //Step 2 : Now convert all nums to 1 which are less than 1 or greater than n
    for(int i = 0; i<n;i++){
        if(arr[i] <= 0 || arr[i] > n)
            arr[i] = 1;
    }

  //Step 3 : Convert all nums, such that all nums have values > n
  for(int i = 0; i<n;i++){
    arr[(arr[i]-1)%n] += n;
  }

 //Step 4 : Traverse again and if there's a value with less than n, then return it's index+1;

 for(int i = 0; i<n;i++){
    if(arr[i] <= n)
        return i+1;
 }

 //if there's no such value, then it for sure will n+1
 return n+1;
}

int main(){
    vector<int> arr = {3,4,-1,1};

    int n = arr.size();

    cout<<findFirstMissingPositive(arr,n);

    return 0;
}