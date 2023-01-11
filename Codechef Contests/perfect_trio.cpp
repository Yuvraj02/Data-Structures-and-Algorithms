#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int t;
    cin>>t;
    while (t--)
    {
        int A,B,C,maxNum=INT32_MIN;
        cin>>A>>B>>C;

        if(A+B==C || B+C==A || C+A == B){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }
    

}