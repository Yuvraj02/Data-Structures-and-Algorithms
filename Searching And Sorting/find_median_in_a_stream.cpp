#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int main(){

    vector<int> A = {5,15,1,3};
    priority_queue<int,vector<int>,greater<int>> minHeap;
    priority_queue<int> maxHeap;

    for(int i = 0; i<A.size();i++){
        //We want elements in maxHeap first so try to add there
        if(maxHeap.empty() || A[i]<maxHeap.top())
            maxHeap.push(A[i]);
        else
            minHeap.push(A[i]);

        //Balance Heaps
        if(maxHeap.size() > minHeap.size()+1){
            //Then put one element from maxHeap to minHeap
            int val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
        }else if(minHeap.size()>maxHeap.size()){
            //Else put element from minHeap to maxHeap
            int val1 = minHeap.top();
            minHeap.pop();
            maxHeap.push(val1);
        }   

        int n1 = maxHeap.size();
        int n2 = minHeap.size();

        if((n1+n2)%2==1){
            cout<<maxHeap.top()<<endl;
        }else{
            cout<<(maxHeap.top()+minHeap.top())/2<<endl;
        }

    }


    


    return 0;
}