#include <iostream>

using namespace std;

void reachHome(int n,int destination){
    if(n==destination) {
        cout<<"Reached"<<endl;
        return;
    }
    reachHome(n+1,destination);
}

int main(){

    int source = 0,destination=10;
    
    reachHome(source,destination);

    return 0;
}