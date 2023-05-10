#include <iostream>
#include <vector>
using namespace std;

int permCoef(int n,int k){
    
    if(k==0)
        return 1;

    if(k==1 || n==1)
        return n;

    if(n==0)
        return 1;
    
    return n * permCoef(n-1,k-1);
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<permCoef(n,k)<<endl;
    }

    return 0;
}

// P(10, 2) = 90
// P(10, 3) = 720
// P(10, 0) = 1
// P(10, 1) = 10