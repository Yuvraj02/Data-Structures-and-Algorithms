#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool isSorted(vector<int>& A,int n){

    if(n==0){
        return true;
    }
    
    if(A[n]<A[n-1])
        return false;

    return isSorted(A,n-1);

}


int main(){
    vector<int> A = {1,2,3,4,5,6};

    cout<<boolalpha<<isSorted(A,A.size()-1);

    return 0;
}