#include <iostream>

using namespace std;

int main(){

string s = "aabaa";
string m = "";

m+=s[0];

for (int i = 1; i < s.size(); i++)
{
    if(s[i]!=s[i-1])
        m+=s[i];
}

cout<<m;

}