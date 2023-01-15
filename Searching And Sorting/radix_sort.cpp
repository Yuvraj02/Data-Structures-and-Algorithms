#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


int main(){

    vector<int> A = {10,9,8,7,6,5,4,3,2,1};
    int max_digits = INT32_MIN;

    for(int i =0; i<A.size();i++){
        int currentDigit = floor(log10(A[i])+1);
        max_digits = max(max_digits,currentDigit);
    }

    int factor = 1;
    while (max_digits>0)
    {

            //Perform counting sort on last digit
            vector<int> count(10,0),output(A.size());
            int lastDigit;
            for (int i = 0; i < A.size(); i++)
            {
                lastDigit = A[i]/factor;
                count[lastDigit%10]++;
            }

            //Add up all values
            for(int i = 1;i <count.size();i++){
                count[i]+=count[i-1];
            }

            //Traverse from back and store values

            for(int i = A.size()-1;i>=0;i--){
                lastDigit = A[i]/factor;
                output[count[lastDigit%10]-1] = A[i];
                count[lastDigit%10]--;
            }
            A = output;
            factor *= 10;
            max_digits--;

    }

    for(auto i : A){
        cout<<i<<" ";
    }
    
    return 0;
}