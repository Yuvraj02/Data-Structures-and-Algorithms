#include <iostream> 
class TwoStack {

public:

    // Initialize TwoStack.
    int top1;
    int top2;
    int size;
    int *arr;

    TwoStack(int s) {
        // Write your code here.
        top1 = -1;
        top2 = s;
        size = s;
        arr = new int[size];
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(size-top1 > 1 && top1+1 != top2){
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if(top2 >=1 && top2-1 != top1){
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1>=0)
            return arr[top1--];
        else
            return -1;
    }
    
    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2<size)
            return arr[top2++];
        else
            return -1;
    }
};
