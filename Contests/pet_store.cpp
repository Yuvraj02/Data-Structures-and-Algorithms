#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){

    int t;
    cin>>t;
    while (t--)
    {
        int N;
        cin>>N;

        vector<int> pets (N);

        for (int i = 0; i < N; i++) cin>>pets[i];
       
        if(N%2!=0){
            cout<<"NO";
            continue;
        }
        
        multiset<int> alice,bob;


        for (int i = 0; i < N/2; i++)
        {
            alice.insert(pets[i]);
        }
        
        for (int i = N/2; i < N; i++)
        {
            bob.insert(pets[i]);
        }

        if(alice==bob)
        cout<<"YES";
        else
        cout<<"NO";

    }
    
    return 0;
}