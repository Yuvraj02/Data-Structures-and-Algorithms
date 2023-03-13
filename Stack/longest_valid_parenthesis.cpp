#include <iostream>
#include <stack>

using namespace std;



int maxLength(string s){
    stack<int> st;
    int len = 0;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(ch=='('){
            st.push(i);
        }else{
            st.pop();
            //If stack becomes empty
            if(st.empty()){
                //push ith index, and calculate from this point now
                st.push(i);
            }else{
                len = max(len, i-st.top());
            }
        }
    }
    return len;
}

int main(){

    string s = "((()";

    cout<<maxLength(s);

    return 0;
}