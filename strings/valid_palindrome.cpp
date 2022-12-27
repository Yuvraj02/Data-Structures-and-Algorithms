#include <iostream>
#include <string>

using namespace std;

string reverse(string s){

    int i=0,j=s.size()-1;

    while (i<j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
    
    return s;
}

int main(){

    string s = "0P";
    string formatted="";

    for (int i = 0; i < s.size(); i++)
    {
        if((s[i]>='A' && s[i]<='Z') ||
           (s[i]>='a' && s[i]<='z') || 
           (s[i]>='0' && (s[i]<='9'))){
            formatted += tolower(s[i]);
        }
    }
    
    if(formatted == reverse(formatted))
        cout<<"True";
    else
        cout<<"False";

}