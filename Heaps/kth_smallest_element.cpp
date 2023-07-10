#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    vector<int> A = {7,10,4,3,20,15};
    int k = 3;

    priority_queue<int> pq;

    for(int i = 0;i<k;i++)
        pq.push(A[i]);
    
    for(int i = k; i<A.size();i++){
        if(A[i] < pq.top()){
            pq.pop();
            pq.push(A[i]);
        }
    }

    cout<<pq.top();
    
    return 0;
}