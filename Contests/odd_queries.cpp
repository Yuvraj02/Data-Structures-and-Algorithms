#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> arr(n);

        for(int i=0;i<n;i++)
            cin>>arr[i];

        while(q--){
            vector<int> clone = arr;
            int a,b,k;
            cin>>a>>b>>k;

            for(int i = a-1 ; i < b ;i++)
                clone[i] = k;

            int total = 0;

            for(int i = 0; i < n; i++)
                total+=clone[i];

            //cout<<total<<endl;
            if(total%2==1)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;

        }
                
    }


    return 0;
}