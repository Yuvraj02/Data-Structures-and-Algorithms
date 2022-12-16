#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){

    vector<int> A = {1,2,7,8,3,9};

    //cout<<maxSum(A,A.size(),2) ;

   A.sort(A.begin(),A.end(),greater<int>());

    return 0;
}