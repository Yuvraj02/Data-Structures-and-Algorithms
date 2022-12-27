#include <iostream>

using namespace std;

int reachNways(int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    return reachNways(n-1)+reachNways(n-2);
}


int main(){

    cout<<reachNways(2)<<endl;

    return 0;
}