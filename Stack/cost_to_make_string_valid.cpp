#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string &str) {
  // Write your code here

    if(str.size()%2!=0)
        return -1;

    stack<char> stack;

    for(int i=0;i<str.size();i++){
        if(str[i] == '{'){
            stack.push(str[i]);
        }else if (!stack.empty() && (stack.top()=='{' && str[i]=='}'))
        {
            stack.pop();
        }else{
            stack.push(str[i]);
        }
    }

    int a = 0,b=0;
    while (!stack.empty())
    {
        if(stack.top()=='{')
            a++;
        else
            b++;

        stack.pop();
    }

    if((a+b)%2==0){
        return ((a+1)/2) + ((b+1)/2);
    }else{
        return -1;
    }
    
}

int main(){

    string s;
    cin>>s;
    cout<<findMinimumCost(s);
}