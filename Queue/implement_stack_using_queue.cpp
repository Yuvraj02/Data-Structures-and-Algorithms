#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:

    queue<int> q;

    MyStack() {
        
    }
    
    void reverse(queue<int> &q){
        if(q.empty())
            return;

        int val = q.front();
        q.pop();
        reverse(q);
        q.push(val);
    }

    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        reverse(q);
        int x = q.front();
        q.pop();
        reverse(q);
        return x;
    }
    
    int top() {
        reverse(q);
        int x = q.front();
        reverse(q);
        return x;
    }
    
    bool empty() {
        return q.empty();
    }
};

int main(){
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.pop();

}