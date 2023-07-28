#include <iostream>

using namespace std;

void nStarTriangle(int n) {
    // Write your code here.
    int counter = 1;

    for(int i = 1; i<=n;i++){
        for(int j = 0; j<n-i;j++)
            cout<<" ";
        
        for(int k=1;k<=counter;k++){
            cout<<"*";
        }
        cout<<endl;
        counter+=2;
    }

    }

int main(){

    int n;
    cin>>n;
    nStarTriangle(n);
    return 0;
}