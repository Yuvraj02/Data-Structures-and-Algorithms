#include <queue>
#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
    int data;
    int i;
    int j;

    node(int data, int i, int j){
        this->data = data;
        this->i = i;
        this->j = j;
    }
};

class compare{
    public:
    
    bool operator()(node *a, node *b){
        return a->data > b->data;
    }
};


int kSorted(vector<vector<int>> &arr, int k, int n) {
    // Write your code here.

    int mini = INT32_MAX,maxi = INT32_MIN;

    priority_queue<node*, vector<node*>, compare> minHeap;

    //Push first k elements to the minHeap
    for(int i = 0; i<k;i++){
        minHeap.push(new node(arr[i][0],i,0));
        maxi = max(maxi, arr[i][0]);
        mini = min(mini, arr[i][0]);
    }

    int start = mini, end = maxi;
    
    while(!minHeap.empty()){

        node *top = minHeap.top();
        minHeap.pop();
        
        mini = top->data;

        if(maxi-mini < end - start){
            start = mini;
            end = maxi;
        }

        int i = top->i;
        int j = top->j;

        if(j+1 < n){
            minHeap.push(new node(arr[i][j+1], i,j+1));
            maxi = max(maxi, arr[i][j+1]);
        }else{
            break;
        }
    }
    return end-start+1;
}