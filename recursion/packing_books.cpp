#include <iostream>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int X,Y,Z;
        int flag,boxes=0;
        cin>>X>>Y>>Z;

        int remainder = Y%Z;

        if(remainder==0){
            cout<<X*(Y/Z)<<endl;
        }else{
            cout<<X*((Y/Z)+1)<<endl;
        }
        
    }

    return 0;
}