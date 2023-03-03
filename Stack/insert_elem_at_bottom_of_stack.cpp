#include <iostream>
#include <stack>

using namespace std;

void solve(stack<int>& myStack, int x,int count,int size){

    if(count==size){
        myStack.push(x);
        return;
    }

    int topVal = myStack.top();
    myStack.pop();
    solve(myStack,x,count+1,size);
    myStack.push(topVal);

}

int main(){

    stack<int> myStack;
    myStack.push(2);
    myStack.push(4);
    myStack.push(6);
    int x = 1;

    int size = myStack.size();
    solve(myStack,x,0,size);
    
    while (!myStack.empty())
    {
        cout<<myStack.top()<<endl;
        myStack.pop();
    }

    return 0;
}