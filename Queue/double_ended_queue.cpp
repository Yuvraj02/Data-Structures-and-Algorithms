#include <iostream>
#include <iomanip>
using namespace std;

class Deque
{
public:
    // Initialize your data structure.
    int *arr;
    int size;
    int rear;
    int front;
    Deque(int n)
    {
        // Write your code here.
        size = n;
        arr = new int[size];
        front=rear=-1;

    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        //Check for full queue
        if((front==0 && rear == size-1) || (rear==(front-1)%(size-1)))
            return false;

        //Check for first element
        if(front==-1) front=rear=0;
        else if(front==0) front = size-1;
        else front--;

        arr[front] = x;

        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if((front==0 && rear == size-1) || (rear==(front-1)%(size-1)))
            return false;

        //Check for first element
        if(front==-1)
            front=rear=0;
        else if(rear==size-1)  rear = 0;
        else rear++;

        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(front==-1)
            return -1;

        int data = arr[front];
        //Check if there's only one element
        if(front==rear) front=rear=-1;
        else if(front==size-1) front = 0;
        else front++;

        return data;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(front==-1) return -1;

        //Check if there's only one element
        int data = arr[rear];
        if(front==rear) front=rear=-1;
        else if(rear==0) rear = size-1;
        else rear--;

        return data;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(front==-1)
            return -1;
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(rear==-1)
            return -1;
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front==-1)
            return true;
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1)))
            return true;
        
        return false;
    }
};

int main(){

    Deque q(5);
    cout<<boolalpha<<q.pushFront(10)<<endl;
    cout<<boolalpha<<q.pushRear(20)<<endl;
    cout<<boolalpha<<q.pushRear(40)<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.pushFront(30)<<endl;
    cout<<q.getFront()<<endl;
    return 0;
}