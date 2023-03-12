#include <iostream>
#include <stack>

using namespace std;


string infixToPostfix(string str) {
    
    stack<char> s;
    string expression = "";
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(ch=='('){
            s.push(ch);
        }else if (ch == '^'){
           s.push(ch);
        }else if (ch=='*' || ch=='/'){
            //Check For Associativity
            while(!s.empty() && (s.top()!= ')' || s.top() != '(') && (s.top()=='*' || s.top() == '/')){
                    expression.push_back(s.top());
                    s.pop();
            }

            //Check For Precedence
            while (!s.empty() && (s.top()!= ')' || s.top() != '(') && (s.top()!= '+' || s.top()!= '-'))
            {
                expression.push_back(s.top());
                s.pop();
            }
            
            s.push(ch);

        }else if (ch == '+' || ch=='-'){
             //Check For Associativity
            while(!s.empty() && (s.top()!= ')' || s.top() != '(') && (s.top()=='+' || s.top() == '-')){
                    expression.push_back(s.top());
                    s.pop();
            }

            //Check For Precedence
            while (!s.empty() && (s.top()!= ')' || s.top() != '(') && (s.top()!= '+' || s.top()!= '-'))
            {
                expression.push_back(s.top());
                s.pop();
            }
            
            s.push(ch);

        }else if (ch == ')'){
            while (s.top()!='(')
            {
                expression.push_back(s.top());
                s.pop();
            }
            s.pop();
        }else{
            expression.push_back(ch);
        }
    }

    while(!s.empty()){
        expression.push_back(s.top());
        s.pop();
    }
    
    return expression;

}

int main(){

    string s = "a+b*c+d";

    cout<<infixToPostfix(s);

    return 0;
}