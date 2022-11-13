#include <iostream>

using namespace std;


int twopowerN(int n){

    if(n==0){
        return 1;
    }

    return 2*twopowerN(n-1);
}

int main(){
    int n;
    cin>>n;

    cout<<twopowerN(n);
    return 0;
}