#include <iostream>
#include <stack>

using namespace std;


void insertionSort(stack<int> &stack, int val){
    if(stack.empty() || stack.top() < val){
        stack.push(val);
        return;
    }

    int topVal = stack.top();
    stack.pop();

    insertionSort(stack,val);
    stack.push(topVal);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty())
        return;

    int topVal = stack.top();
    stack.pop();

    sortStack(stack);
    
    insertionSort(stack, topVal);

}

int main(){

    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(9);
    st.push(2);

    sortStack(st);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}