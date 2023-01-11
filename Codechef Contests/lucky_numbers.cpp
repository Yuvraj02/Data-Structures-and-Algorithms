#include <iostream>

using namespace std;


int main(){ 

    int t;
    cin>>t;

    while (t--)
    {
        int X;
        cin>>X;
        bool isLucky = 0;
        while (X!=0)
        {
            int remainder = X%10;
            if(remainder==7){
                isLucky=1;
                break;
            }

            X/=10;
        }
        
        if(isLucky)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
    

    return 0;
}