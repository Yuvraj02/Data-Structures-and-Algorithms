#include <iostream>

using namespace std;

int main(){
    int A[] = {1,7,6,10,9};
    int N = sizeof(A)/sizeof(A[0]);
    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < N-1; j++)
        {
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
            }
        }
        
    }

    for (auto i : A)
    {
        cout<<i<<" ";
    }
    
    
    return 0;
}