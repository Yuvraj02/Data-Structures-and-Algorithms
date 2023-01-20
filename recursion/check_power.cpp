#include <iostream>

using namespace std;

int pow(int a, int b){
    if(b==0)
        return 1;
    
    if(b%2==0)
        //(a^b/2 * a^b/2)
       return pow(a,b/2)*pow(a,b/2);
    else
        return a * (pow(a,b/2)*pow(a,b/2));
}


int main(){

    cout<<pow(3,2);

    return 0;
}