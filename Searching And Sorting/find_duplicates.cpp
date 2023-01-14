#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){

    vector<int> A = {13,9 ,25 ,1 ,1 ,0 ,22 ,13 ,22 ,20 ,3 ,8 ,11 ,25, 10 ,3 ,15 ,11 ,19 ,20 ,2 ,4 ,25 ,14,23,14};

    vector<int> finalVec;

    for(int i = 0; i<A.size();i++){

        if(A[abs(A[i])-1] < 0)
            finalVec.push_back(abs(A[i]));
        else
            A[abs(A[i])-1] = -A[abs(A[i])-1];
    }

    sort(finalVec.begin(),finalVec.end());

    for(auto i : finalVec){
        cout<<i<<" ";
    }
    if(finalVec.size()==0)
        cout<<-1;

    return 0;
}