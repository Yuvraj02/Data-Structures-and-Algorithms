#include <iostream>

using namespace std;
//Log N solution
int pow(int a, int b){

    if(b==0)
        return 1;
    if(b==1)
        return a;

    if(b%2==0)
        return pow(a,b/2) * pow(a,b/2);
    else
        return a * pow(a,b/2) * pow(a,b/2);
}

int main(){

    cout<<pow(2,5)<<endl;

    return 0;
}
