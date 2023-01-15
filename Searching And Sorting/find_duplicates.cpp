#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){

    vector<int> A = {1,2,3,4,3};
    vector<int> finalVec;

    //Traverse the array and change each value of A[A[i]%size] to A[A[i]%size] + size;

    for(int i = 0; i<A.size();i++)
        A[A[i]%A.size()] = A[A[i]%A.size()] + A.size();

    for (int i = 0; i < A.size(); i++)
    {
        if(A[i] >=A.size()*2){
            finalVec.push_back(i);
        }
    }

    cout<<A.size()<<endl;
    
    sort(finalVec.begin(),finalVec.end());
    for(auto i : finalVec){
        cout<<i<<" ";
    }
    if(finalVec.size()==0)
        cout<<-1;

    return 0;
}