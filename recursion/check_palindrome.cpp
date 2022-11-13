#include <iostream>

using namespace std;


bool checkPalindrome(string s,int a){

  if(s[a] != s[(s.size()-1)-a]){
    return false;
  }
  if(a>(s.size()-1)-a){
    return true;
  }  

    return checkPalindrome(s,a+1);

}

int main(){
    string s = "abca";
    cout<<checkPalindrome(s,0);
    return 0;
}