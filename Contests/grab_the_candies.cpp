#include <iostream>
#include <vector>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        vector<int> candies(n);
        for(int i=0;i<n;i++)
            cin>>candies[i];

        int mihai = 0, bianca = 0;

        for(int i=0;i<n;i++){
            if(candies[i]%2==0)
                mihai+=candies[i];
            else
                bianca+=candies[i];
        }

    if(mihai>bianca)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }

    return 0;
}