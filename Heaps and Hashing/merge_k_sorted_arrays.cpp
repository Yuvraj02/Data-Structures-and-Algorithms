#include <queue>
#include <iostream>
#include <vector>

using namespace std;
class node{
    public:
        int data;
        int i,j;

        node(int data, int i ,int j){
            this->data = data;
            this->i = i;
            this->j = j;
        }
};

class comparator{
    public:
    bool operator()(node *a, node *b){
        return a->data > b->data;
    }

};



vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*, vector<node*>, comparator> minHeap;

    for(int i =0 ;i<k;i++){
        node *newNode = new node(kArrays[i][0], i,0);
        minHeap.push(newNode);
    }

    vector<int> ans;

    while(minHeap.size() > 0){
        node *top = minHeap.top();
        minHeap.pop();

        ans.push_back(top->data);
        int i = top->i;
        int j = top->j;
        if (j + 1 < kArrays[i].size()) {
          node *newNode = new node(kArrays[i][j + 1], i, j + 1);
          minHeap.push(newNode);
        }
    }

    return ans;
}
