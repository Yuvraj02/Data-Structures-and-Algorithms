#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){

    vector<int> A = {1, 2, 3};
    vector<int> maxSuffix (A.size());

    set<int> smallest;
    int max_so_far = INT32_MIN,maxSumTriplet=INT32_MIN;
    for (int i = maxSuffix.size()-1; i>=0 ; i--)
    {   
            max_so_far = max(max_so_far,A[i]);
            maxSuffix[i]=max_so_far;
    }

    for (int i = 0; i < A.size(); i++)
    {
        smallest.insert(A[i]);

        auto it = smallest.find(A[i]);

        if(it == smallest.begin() || A[i]==maxSuffix[i])
            continue;

        if(it != smallest.end()){
            it--;
            maxSumTriplet = max(maxSumTriplet, A[i]+maxSuffix[i]+*it);
        }

    }
    
}