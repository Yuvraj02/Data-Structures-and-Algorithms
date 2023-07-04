#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main(){

    vector<int> arr = {2,2,3,2};

   int result = 0;
        for(int i = 0; i<32; i++){
            int sum = 0;
            int mask = 1<<i;

            for(int i = 0; i<arr.size();i++){
                    if(arr[i] & mask)
                        sum++;
            }

            if(sum%3!=0)
                result = result | mask;
        }
    
    cout<<result;
    return 0;
}