#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//Using Recursion
void reverse(queue<int> &q){

    if(q.empty()){
        return ;
    }

    int front = q.front();
    q.pop();

    reverse(q);
    q.push(front);
}

//Using Stack
void reverseUsingStack(queue<int> &q){

    stack<int> s;
    while(q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(s.empty()){
        q.push(s.top());
        s.pop();
    }    
}

queue<int> rev(queue<int> &q)
{
        reverse(q);
        return q;
}

void printQueue(queue<int> q){

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){

    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    printQueue(q);

    rev(q);

    printQueue(q);

    return 0;
}