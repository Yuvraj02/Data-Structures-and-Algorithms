#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin>>t;

    while (t--)
    {
        int N,X;
        cin>>N>>X;

        vector<int> A,B;
        
        for(int i=0;i<N;i++){
            int elem;
            cin>>elem;
            A.push_back(elem);
        }

        for(int i=0;i<N;i++){
            int elem;
            cin>>elem;
            B.push_back(elem);
        }

        int sum=0;
        for (int i = 0; i < N; i++)
        {
            if(A[i]>=X)
                sum+=B[i];
        }
        
        cout<<sum<<endl;
    }
    

    return 0;
}