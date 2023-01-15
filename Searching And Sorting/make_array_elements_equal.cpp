#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> A = {1,8,19};

    sort(A.begin(),A.end());

    int mid = (A.size()-1)/2;
    int bestVal = A[mid];
    int cost=0;
    for(int i = 0;i<A.size();i++){
        if(mid==i)
            continue;
        cost+=abs(bestVal-A[i]);
    }
    cout<<cost;
    return 0;
}