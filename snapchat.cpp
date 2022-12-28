#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin>>t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<long int> chef(N),chefina(N);
        for (int i = 0; i < N; i++) cin>>chef[i];

        for (int i = 0; i < N; i++) cin>>chefina[i];
            
        int streak=0;

        for (int i = 0; i < N; i++)
        {
            if (chef[i]!=0 && chefina[i]!=0)
            {
                streak++;
            }    
        }

        cout<<streak<<endl;
    }
    
    return 0;
}