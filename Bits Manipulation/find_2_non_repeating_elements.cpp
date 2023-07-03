#include <iostream>
#include <vector>
using namespace std;

int main(){
vector<int> arr = {1, 2, 3, 2, 1, 4};

    int a = 0;
    int b = 0;

    int xor_sum = 0;

    //First get xor_sum
    for(int i = 0; i<arr.size();i++)
        xor_sum^=arr[i];

    //Now the xor_sum would be 3^4
    //Get the right most set bit of this xor_sum

    //Formula to get right most set bit is
    int rightMostSetBit = xor_sum & ~(xor_sum-1);

    //Now divide the numbers according to this set bit
    //If the number has same right most set bit position then it is a
    //Otherwise it is B      
    for(int i = 0; i<arr.size();i++){
        if(arr[i]&rightMostSetBit)
            a ^= arr[i];
        else
            b ^= arr[i];
    }

    cout<<a<<" "<<b;
    return 0;
}