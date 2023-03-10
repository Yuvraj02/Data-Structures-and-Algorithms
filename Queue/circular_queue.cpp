#include <iostream> 
#include <iomanip>

using namespace std;

class CircularQueue{
    public:
    // Initialize your data structure.
    int *arr;
    int size;
    int front;
    int rear;

    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int[size];
        front=rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        //Check if queue is full
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1)))
            return false;

        if(front==-1){
            front=rear=0;
        }else if (rear==size-1 && front!=0){
            rear = 0;
        }else{
            rear++;
        }
         arr[rear] = value;
    return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(front==-1)
            return -1;

        //Check for 1 element only
        int data = arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }else if (front==size-1){
            front = 0;
        }else{
            front++;
        }

        return data;
    }
};

int main(){

CircularQueue q(5);
cout<<boolalpha<<q.enqueue(5)<<endl;
cout<<boolalpha<<q.enqueue(4)<<endl;
cout<<boolalpha<<q.enqueue(3)<<endl;
cout<<boolalpha<<q.enqueue(2)<<endl;
cout<<boolalpha<<q.enqueue(1)<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;

return 0;
}