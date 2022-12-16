#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> A = {1,2,3,4,5,6};

    for (int i = 0; i < A.size(); i+=2)
    {
        if(i != A.size()-1)
        swap(A[i],A[i+1]);
        
    }
    
    for (auto i : A)
    {
        cout<<i;
    }
    
    return 0;
}