#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string convertToNumeric(string s){

vector<string> keyPad= {"2","22","222","3","33","333",
                         "4","44","444","5","55","555","6","66","666",
                        "7","77","777","7777","8","88","888","9","99","999","9999"};

string numeric = "";

for (int i = 0; i < s.size(); i++)
{
    if(s[i]==' ')
        numeric+='0';
    else
        numeric+= keyPad[tolower(s[i])-'a'];
}

return numeric;

}

int main(){

    string s;
    cout<<"Enter A message : ";
    getline(cin,s);

    cout<<convertToNumeric(s);

}