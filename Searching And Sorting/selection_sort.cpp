#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> A = {29,72,98,13,87,66,52,51,36};

    int minVal = A[0];
    int minIndex = 0;
    for (int i = 0; i < A.size()-1; i++)
    {
        minVal = INT32_MAX;
       for (int j = i; j < A.size(); j++)
       {
            if(A[j]<minVal){
                minIndex=j;
                minVal = A[j];
            }
       }
       
        swap(A[i],A[minIndex]);
        
    }
    
    for (auto i: A)
    {
        cout<<i<<" ";
    }
    

    return 0;
}