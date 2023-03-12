#include <iostream>

using namespace std;

class Deque{
    private:
        int val;
        Deque *next;
        Deque *prev;
        Deque *front;
        Deque *rear;
   
    public:
    //Initialize to NULL if no params are passed
    Deque(){
        this->next = NULL;
        this->prev = NULL;
        front = NULL;
        rear = NULL;
    }

    //If value is passed 
    private:
    Deque(int val){
        this->val = val;
        this->next = NULL; 
        this->prev = NULL;   
    }

    public:
    void push_back(int x){
        Deque *newNode = new Deque(x);
        //If first node 
        if(front==NULL){
            front = newNode;
            rear = front;
        }else{
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void push_front(int x){
        //If First node
        Deque *newNode = new Deque(x);
        if(front==NULL){
            front = newNode;
            rear = newNode;
        }else{
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void pop_front(){
        //Check for stack underflow
        if(!front){
            cout<<"Deque is Empty"<<endl;
            return;
        }

        Deque *node_to_delete = front;
        front = front->next;
        front->prev = NULL;
        delete node_to_delete;
    }

    void pop_back(){
        if(!front){
            cout<<"Deque is Empty"<<endl;
            return;
        }

        Deque *node_to_delete = rear;
        rear = rear->prev;
        rear->next=NULL;
        delete node_to_delete;
    }

    int front_data(){
        if(!front){
            cout<<"Deque is Empty"<<endl;
            return -1;
        }
       return front->val; 
    }

    int back(){
        if(!front){
            cout<<"Deque is Empty"<<endl;
            return -1;
        }
        return rear->val;
    }

    bool empty(){
        if(!front)
            return true;
        
        return false;
    }

};

int main(){

    Deque q;
    q.pop_back();
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    cout<<q.front_data();

    return 0;
}