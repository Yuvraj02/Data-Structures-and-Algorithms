#include <iostream>

using namespace std;

class KQueue{
    public:
        int *arr;
        int *next;
        int *front;
        int *rear;
        int n;
        int s;
        int freeslot;

        KQueue(int n, int s){
            this->n = s;
            this->s = s; //Size of array
            arr = new int[s];
            next = new int[s];
            front = new int[n];
            rear = new int[n];

            //Initialize Front and rear
            for(int i=0;i<n;i++){
                front[i] = -1;
                rear[i] = -1;
            }

            //Initialize next
            for(int i=0 ; i<s;i++)
                next[i] = i+1;
            
            next[s-1] = -1;
            freeslot = 0;
        }

        bool push(int x, int m){
            if(freeslot==-1) //If queue is full
                return false; 

            //Get a freeslot
            int index = freeslot;
            //Update freeslot to next freeslot
            freeslot = next[freeslot];

            //Check if the element is first element
            if(front[m-1]==-1)
                front[m-1] = index;
            else //Link previous element to current element
                next[rear[m-1]] = index;

            //Update next of current element
            next[index] = -1;
            //Update rear of the queue
            rear[m-1] = index;
            //Push element to Queue
            arr[index] = x;

            return true;
        }

    int pop(int m){
        if(front[m-1]==-1) //If queue is empty 
            return -1;

        //Get current elements index
        int index = front[m-1];
        //Update front to previous
        front[m-1] = next[index];
        //Update next index value back to free slot
        next[index] = freeslot;
        //Freeslot is now the current index
        freeslot = index;

        return arr[index];
    }

};

int main(){

    KQueue q(3,9);
    q.push(1,1);
    q.push(1,2);
    q.push(4,1);
    cout<<q.pop(1)<<endl;
    cout<<q.pop(1)<<endl;
    cout<<q.pop(2)<<endl;
    cout<<q.pop(1);

    return 0;
}