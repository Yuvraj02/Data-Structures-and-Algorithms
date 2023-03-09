#include <iostream>
#include <stack>

using namespace std;


class SpecialStack {
    // Define the data members.

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
    stack<int> s;
    int minVal;
    
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            minVal = data;
        }else if(data < minVal){
            int val = 2*data-minVal;
            s.push(val);
            minVal = data;
        }else{
            s.push(data);
        }
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty()) return -1;

        int data = s.top();
        s.pop();

        if(data < minVal){
            int prevVal = minVal;
            //Previous Minimum Value
            int val = 2*minVal-data;
            minVal = val;
            return prevVal;
        }else{
            return data;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()) return -1;

        int data = s.top();
        if(data < minVal){
            return minVal;
        }else{
            return data;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return s.empty();
        
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()) return -1;
        return minVal;
    }  
};

int main(){
    SpecialStack s;
   s.push(5);
   s.push(4);
   s.push(6);
   cout<<s.getMin();
    return 0;
}