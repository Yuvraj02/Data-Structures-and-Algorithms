#include <iostream>

using namespace std;

class Queue {
public:
    int *arr;
    int qfront;
    int rear;
    int size;
    Queue() {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront==rear) return true;

        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear==size){
            cout<<"Queue is full"<<endl;
        }else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront==rear)
            return -1;

        int data = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if(qfront==rear){
            qfront=0;
            rear =0;
        }
        return data;
    }

    int front() {
        // Implement the front() function
        if(qfront==rear)
            return -1;
        
        return arr[qfront];
    }
};

int main(){

    Queue q;
    q.enqueue(2);
    q.enqueue(5);
    cout<<q.dequeue();

    return 0;
}