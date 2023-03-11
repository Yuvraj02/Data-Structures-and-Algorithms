#include <iostream>

#include <queue>

using namespace std;

void kReverse(queue<int> &q, int k){
    if(q.empty() || k==0)
        return;

    int val = q.front();
    q.pop();
    kReverse(q,k-1);
    q.push(val); 

}

queue<int> modifyQueue(queue<int> &q, int k) {
        kReverse(q, k);  
        int leftOvers = q.size()-k;
        for (int i = 0; i < leftOvers; i++)
        {
            q.push(q.front());
            q.pop();
        }
        
        return q;
}

void printQueue(queue<int> q){

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k =3;
    printQueue(q);
    modifyQueue(q,k);
    printQueue(q);
    return 0;
}