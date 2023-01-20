#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool find(vector<int> A, int key,int n){

    if(n==-1)
        return false;
    if(A[n]==key)
        return true;

    return find(A,key,n-1);
}

int main(){

    vector<int> A = {3,1,2,4,6,1};

    int key = 2;

    cout<<boolalpha<<find(A,key,A.size()-1);


    return 0;
}
