#include <iostream>
#include <vector>

using namespace std;

vector<int> findCommonElements(vector<int> &A, vector<int> &B,vector<int> &C){

int i=0,j=0,k=0;
vector<int> finalVec;
while (i<A.size() && j<B.size() &&k<C.size())
{
    if(A[i]<B[j] || A[i]<C[k]){
        i++;
    }else if(B[j]<A[i] || B[j]<C[k]){
        j++;
    }else if(C[k]<A[i] || C[k]<B[j]){
        k++;
    }else{
        if(A[i-1]!=A[i])
            finalVec.push_back(A[i]);
        i++;
        j++;
        k++;
    }
}

return finalVec;
}

int main(){
vector<int> A = {4,6,8} ;
vector<int> B = {6} ;
vector<int> C = {2,2,6} ;

vector<int> commonElements = findCommonElements(A,B,C);
for (auto i : commonElements)
{
    cout<<i<<" ";
}


}