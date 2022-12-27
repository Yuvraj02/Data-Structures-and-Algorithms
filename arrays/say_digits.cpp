#include <iostream>

using namespace std;


void sayDigit(int n, string arr[]){
    if(n==0){
        return ;
    }

    sayDigit(n/10, arr);
    cout<<arr[n%10]<<" ";
}


int main(){

    string arr[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    int n;
    cin>>n;
    sayDigit(n,arr);
    cout<<endl;
    return 0;
}