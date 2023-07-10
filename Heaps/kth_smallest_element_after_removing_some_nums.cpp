#include <iostream>
#include <vector>
using namespace std;


int main(){
    // Write your code here.
    vector<int> arr={1,3};
    int k = 2;
    //If array elements are less than or equal to k, then increment k otherwise break
    for(int i = 0 ; i<arr.size();i++){
        if(arr[i]<=k)
            k++;
        else
            break;
    }
    cout<<k;
    return 0;
}