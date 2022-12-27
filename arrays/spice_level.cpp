#include <iostream>

using namespace std;

int main(){

    int t;
    cin>>t;
    while (t--)
    {
        int spice;
        cin>>spice;
        if(spice<4)
            cout<<"MILD"<<endl;
        else if(spice>=4 && spice<7)
            cout<<"MEDIUM"<<endl;
        else
            cout<<"HOT"<<endl;
    }
    

    return 0;
}