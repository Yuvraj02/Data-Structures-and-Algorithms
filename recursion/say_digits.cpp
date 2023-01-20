#include <iostream>
#include <vector>
using namespace std;

void sayDigits(int n){

vector<string> digits = {"zero","one","two","three","four","five","six","seven","eight","nine"};
if(n==0) return;

sayDigits(n/10);
int digit=n%10;
cout<<digits[digit]<<" ";
}

int main(){
    sayDigits(109);
    return 0;
}