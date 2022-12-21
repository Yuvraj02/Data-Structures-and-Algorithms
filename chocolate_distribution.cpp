#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int m=5;

    vector<long long> A = {3, 4, 1, 9, 56, 7, 9, 12};

    sort(A.begin(),A.end());

    long long int i=0,j=m-1, minNum = INT32_MAX;

    while (j<A.size())
    {
        minNum = min(A[j]-A[i],minNum);
        i++,j++;
    }
    
    cout<<minNum;

    // for (auto i : A)
    // {
    //     cout<<i<<" ";
    // }
    
    return 0;
}