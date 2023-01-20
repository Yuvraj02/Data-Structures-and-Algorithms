#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> A, int n){

    if(n==0){
        return A[n];
    }

return A[n] + sum(A,n-1);
}

int main(){

vector<int> A = {6,4,2,8,1,10};
cout<<sum(A,A.size()-1);

    return 0;
}