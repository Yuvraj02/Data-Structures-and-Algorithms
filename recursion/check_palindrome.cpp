#include <iostream>
#include <iomanip>

using namespace std;

bool checkPalindrome(string str, int i){
    if(i>(str.size()-i-1))
        return true;
    if(str[i]!=str[str.size()-i-1])
        return false;
    
    return checkPalindrome(str,i+1);
}

int main(){

    string s = "abbccbba";
    if(checkPalindrome(s,0))
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}