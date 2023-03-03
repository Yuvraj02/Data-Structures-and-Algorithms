#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

bool findRedundantBrackets(string &s)
{

    stack<int> stack;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='(' || (s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*')){
            stack.push(s[i]);
        }else {
            if(s[i]==')'){
                bool isRedundant = true;
            while (stack.top()!='(')
            {
                char top = stack.top();
                if((top=='+' || top=='-' || top=='/' || top=='*')){
                    isRedundant = false;
                }
                stack.pop();
            }
             if(isRedundant)
                return true;  

            stack.pop();         
        }
    }
    }
    return false;
}

int main(){

    int t;
    cin>>t;
    while(t--){

        string s;
        cin>>s;
        cout<<boolalpha<<findRedundantBrackets(s)<<endl;

    }
   
    return 0;
}
