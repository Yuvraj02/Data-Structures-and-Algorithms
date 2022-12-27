#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

bool isValid(string s){

        stack<char> st;

        for (auto c : s)
        {
            if(c=='{' || c=='(' || c== '['){
                st.push(c);
            }else if(c=='}' && !(st.empty()) && st.top()=='{'){
                st.pop();
            }else if (c==')' && !(st.empty()) && st.top()=='('){
                st.pop();
            }else if(c==']' && !(st.empty()) && st.top()=='['){
                st.pop();
            }else{
                return false;
            }
        }
    //cout<<"Top Rn is : "<<st.top()<<endl;
        
    if(st.empty())
        return true;
    else
    return false;

}


int main(){

    string s = "{";
    cout<<boolalpha<<isValid(s);
    return 0;
}

