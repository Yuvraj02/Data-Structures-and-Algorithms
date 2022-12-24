#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> A = {1,1};

    int L = 0,R=A.size()-1;

    int maxSum = 0,difference = 0;

   // cout<<min(A[L],A[R]) * ((R-L));

    while (L<R)
    {   
        int temp = maxSum;
        difference = min(A[L],A[R]) * ((R-L));
        maxSum = max(difference,temp);

        if(A[L]<A[R]){
            L++;
        }else{
            R--;
        }
    }
    cout<<maxSum;

    return 0;
}