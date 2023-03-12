#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string str)
{
    stack<int> s;
    int a,b,c;

    for(int i=0;i<str.size();i++){

        char ch = str[i];
        if(ch>='0' && ch<='9'){
            s.push(ch-'0');
        }else{
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            if(ch=='+'){
                c = a+b;
            }else if(ch=='-'){
                c = a-b;
            }else if(ch=='*'){
                c = a*b;
            }else if(ch=='/'){
                c = a/b;
            }
            s.push(c);
        }
    }
    return s.top();
}

int main(){

    string s = "123+*8-";
    cout<<evaluatePostfix(s);
    


    return 0;
}