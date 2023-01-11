#include <iostream>
#include <vector>

using namespace std;

int main(){ 

    vector<int> A = {1,7,9,6,2,9,4,3};

    for (int i = 1; i < A.size(); i++)
    {
        int currentElem= A[i];
        int j = i-1;
        while (j>=0)
        {
            if(A[j]>currentElem){
                A[j+1]=A[j];
            }else{
                break;    
            }
            j--;
        }

        A[j+1]=currentElem;
    }
    
    for(auto i : A){
        cout<<i<<" ";
    }

    return 0;
}