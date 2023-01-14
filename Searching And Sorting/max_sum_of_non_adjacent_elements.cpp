#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> A = {2,1,4,9};
    
    int inclusive=A[0],exclusive=0;

    for (int i = 1; i < A.size(); i++)
    {
        int oldInclusive = inclusive;
        inclusive = max(inclusive,exclusive+A[i]);
        exclusive = oldInclusive;
    }
    
    cout<<inclusive;

    

    return 0;
}