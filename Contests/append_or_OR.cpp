#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin>>t;

    while (t--)
    {
        int n,Y;
        cin>>n>>Y;

        vector<int> A (n);

        for (int i = 0; i < A.size(); i++)
        {
            cin>>A[i];
        }
        
        int bitWiseSum=0;

        for (int i = 0; i < A.size(); i++)
        {
            bitWiseSum |= A[i];
        }

        int start = Y-bitWiseSum;
        bool isPossible = 0;

        int valueToAppend;
        //cout<<bitWiseSum<<endl;
        for (int i = start; i <= Y; i++)
        {
            if((bitWiseSum|i)==Y){
                isPossible=1;
                valueToAppend = i;
                break;
            }
        }
        
    if(isPossible)
    cout<<valueToAppend<<endl;
    else
    cout<<-1<<endl;
    
}
    return 0;
}