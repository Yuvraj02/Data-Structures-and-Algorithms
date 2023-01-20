#include <iostream>

using namespace std;

void reverse(string &s,int i){

    if(i>(s.size()-i-1))
        return;

    swap(s[i],s[s.size()-i-1]);
    reverse(s,i+1);

}


int main(){

    string s = "yuvraj";

    reverse(s,0);
    cout<<s;

    return 0;
}