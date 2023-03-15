#include <iostream>
#include <stack>

using namespace std;

bool duplicateParanthesis(string &expr)
{
    // Write your code here
    stack<char> s;

    for(int i=0 ;i <expr.size();i++){
        char ch = expr[i];
        if(ch!=')'){
            s.push(ch);
        }else{

            if(ch==')'){
                bool isDuplicate = true;
                while(s.top()!='('){

                  if (s.top()!='(') {
                    isDuplicate = false;
                  }
                  s.pop();
                }
                if (isDuplicate)
                  return true;
                s.pop();
            }
        }
    }
    return false;
}

int main(){

    string s = "(a+b)+((c+d))";
    if(duplicateParanthesis(s))
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}