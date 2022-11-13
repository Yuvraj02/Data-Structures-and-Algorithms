#include <iostream>

using namespace std;

void revPrint(int n){
    if(n==0)
        return ;
    cout<<n<<" ";
    revPrint(n-1);
}


int main(){

    revPrint(5);

    return 0;
}