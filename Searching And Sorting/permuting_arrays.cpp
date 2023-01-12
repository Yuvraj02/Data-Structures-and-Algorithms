#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> A = {1,2,3};
    vector<int> B = {7,8,9};
    int k = 10;
    bool yes = true;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());

    for (int i = 0; i < A.size(); i++)
    {
        if(A[i]+B[i]<k){
            yes = false;
            break;
        }
    }
    if(yes)
    cout<<"YES";
    else
    cout<<"NO";

    return 0;
}