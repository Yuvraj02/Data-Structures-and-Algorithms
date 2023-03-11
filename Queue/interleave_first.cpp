#include <iostream>
#include <queue>

using namespace std;

void printQueue(queue<int>);

void interLeaveQueue(queue<int> &q) {
    
    queue<int> temp;

    int n = q.size();
    int half = n/2;

    while(q.size()!=half){
            temp.push(q.front());
            q.pop();
    }
    
    cout<<"Temp: ";
    printQueue(temp);
    cout<<"Original: ";
    printQueue(q);

    while(!temp.empty()){
        q.push(temp.front());
         temp.pop();
        q.push(q.front());
        q.pop();
    }
    
 printQueue(q);
}

void printQueue(queue<int> q){

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){

    queue<int> q;
    for (int i = 1; i <= 6; i++)
        q.push(i);

    printQueue(q);    
    interLeaveQueue(q);
      

}