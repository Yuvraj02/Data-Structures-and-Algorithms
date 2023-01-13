#include <iostream>

using namespace std;

int main(){

    int t;
    cin>>t;

    while (t--)
    {
        int following,followers;
        cin>>following>>followers;

        if(following>(10*followers)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }
    

    return 0;
}