#include <iostream>

using namespace std;

int main(){

    int t;
    cin>>t;
    while (t--)
    {
        int days,tablets;
        cin>>days>>tablets;

        if(tablets/3 >= days){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}