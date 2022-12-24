#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> A = {2,7,11,15};
    int target = 18;
    int L = 0, R = A.size()-1;

    while (A[L]+A[R]!=target)
    {
        if((A[L]+A[R])<target){
            L++;
        }else{
            R--;
        }
    }
    cout<<A[L]<<", "<<A[R];

    return 0;
}