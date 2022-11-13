#include <iostream>

using namespace std;

int main(){

    int t;
    cin>>t;
    while (t--)
    {
        int X,Y;
        cin>>X>>Y;

        X*=2,Y*=5;   
        if(X>Y){
            cout<<"Chocolate"<<endl;
        }else if(X<Y){
            cout<<"Candy"<<endl;
        }else{
            cout<<"Either"<<endl;
        }
    }
    

    return 0;
}