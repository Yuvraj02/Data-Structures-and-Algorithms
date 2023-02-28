#include <iostream>
#include <iomanip>
using namespace std;

class Stack {
    private:
        int topPointer;
        int *arr;
        int size;

     public:
        Stack(int size){
            this->size = size;
            this->topPointer = -1;
            this->arr = new int[size];
        }
   
        void push(int val){
            if(size-topPointer > 1){
                topPointer++;
                arr[topPointer] = val;
            }else{
                cout<<"Stack Overflow"<<endl;
            }
        }

        void pop(){
            if(topPointer >= 0)
                topPointer--;
            else
                cout<<"Stack Underflow"<<endl;
        }

        int top(){
            if(topPointer>=0 && topPointer < size)
                return arr[topPointer];
            
            cout<<"No element in stack"<<endl;
            return -1;
        }

        bool empty(){
            if(topPointer==-1)
                return 1;
            return 0;
        }

        int currentSize(){
            if(topPointer>=0)
                return topPointer+1;
            
            return 0;
        }   
};

int main(){

    Stack s(4);
    s.push(1);
    cout<<s.top()<<endl;
    s.pop();
    cout<<boolalpha<<s.empty()<<endl;
    s.push(2);
    s.push(8);
    cout<<boolalpha<<s.empty()<<endl;
    cout<<s.top()<<endl;
    cout<<s.currentSize();
    return 0;
}