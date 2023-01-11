#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> A = {1,2,3};
    vector<int> B = {4,5,6};

    vector<int> C (A.size()+B.size());

    int i=0,j=0,k=0;

    while (j<A.size() && k<B.size())
    {
      
            if(A[j]<=B[k]){
                C[i]=A[j];
                j++;
            }else{
                C[i]=B[k];
                k++;
            }
            i++;
    }
    
    while (j<A.size())
    {
        C[i]=A[j];
        i++;
        j++;
    }
    
    while (k<B.size())
    {
        C[i]=B[k];
        i++;
        k++;
    }
    
    for (auto i : C)
    {
        cout<<i<<" ";
    }
    
    
    

    return 0;;
}