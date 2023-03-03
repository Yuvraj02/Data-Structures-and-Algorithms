#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

bool isValid(string s) {

     stack<char> st;

     for (int i = 0; i < s.size(); i++)
     {
        if(s[i]=='{'||s[i]=='('||s[i]=='['){
            st.push(s[i]);
        }else if(s[i]==')' && (!st.empty() && st.top()=='(')){
            st.pop();
        }else if(s[i]=='}' && (!st.empty() && st.top()=='{')){
            st.pop();
        }else if (s[i]==']' && (!st.empty() && st.top()=='[')){
            st.pop();
        }else{
            return false;
        }
     }
     
     return st.empty();
}

int main(){
    
    string s= "}";
    cout<<boolalpha<<isValid(s);

    return 0;
}