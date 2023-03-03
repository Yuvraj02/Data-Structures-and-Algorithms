#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int>&stack,int N ,int count, int X){

    if(stack.empty()){
        stack.push(X);
        return;
    }

    int topVal = stack.top();
    stack.pop();
    insertAtBottom(stack,N,count+1,X);
    stack.push(topVal);
}


void reverseStack(stack<int> &stack) {
    // Write your code here
        if(stack.empty())
            return;

        int topVal = stack.top();
        stack.pop();

        reverseStack(stack);

        insertAtBottom(stack,stack.size(), 0,topVal);
}

int main(){

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseStack(s);

    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
    
    return 0;
}