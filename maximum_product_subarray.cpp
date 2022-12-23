#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> A = {-2,0,-1};

    int result = A[0];
    int currMin = A[0], currMax = A[0];
    
    for (int i = 1; i < A.size(); i++)
    {
        int temp = currMax;
        currMax = max({A[i],A[i]*currMax,A[i]*currMin});
        currMin = min({A[i],temp*A[i],currMin*A[i]});
        result = max(result,currMax);
    }
    cout<<result;
}