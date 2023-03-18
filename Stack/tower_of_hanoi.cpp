#include <iostream>

using namespace std;

void towerOfHanoi(int n, char source, char destination, char helper){

    if(n==0)
        return;
    
    towerOfHanoi(n-1, source, helper, destination);
    cout<<"Moving Disk "<<n<<" from "<<source<<" to "<<destination<<endl;
    towerOfHanoi(n-1, helper, destination, source);
}

int main(){

    int N = 2;
    towerOfHanoi(N,'A','C','B');
    return 0;
}