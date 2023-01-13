#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x = 0;

int main(){

    vector<int> A = {1,2,8,4,2,1};
    int x = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i+1; j < A.size(); j++)
        {
            int val = (A[i]&A[j])&x;
            if(val==x && A[j]<A[i]){
                swap(A[i],A[j]);
            }
        }
        
    }
   // cout<<val;

    for (auto i : A)
    {
        cout<<i<<" ";
    }
    

    return 0;
}