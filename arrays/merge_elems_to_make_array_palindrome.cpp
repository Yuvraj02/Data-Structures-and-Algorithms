#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> A = {1,4,6,4,7,1};

    int i = 0, j=A.size()-1,operations=0;

    while (i<j)
    {
        if(A[i]==A[j]){
            i++;
            j--;
        }

        if(A[i]<A[j]){
            A[i+1] +=A[i];
            i++;
            operations++;
        }else if (A[j]<A[i]){
            A[j-1]+=A[j];
            j--;
            operations++;
        }
    }

cout<<operations;

    return 0;
}