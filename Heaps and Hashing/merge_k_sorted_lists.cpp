#include <queue>
#include <iostream>
#include <vector>

using namespace std;
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };


class comparator{
    public:
    bool operator()(Node<int>* a, Node<int>* b){
        return a->data > b->data;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    // Write your code here.
    if(listArray.size()==0)
        return NULL;

    priority_queue<Node<int>*, vector<Node<int>*>, comparator> minHeap;

    for(int i = 0; i<listArray.size();i++){
        //If the node is Not NULL, then push it to the heap
        if(listArray[i])
            minHeap.push(listArray[i]);
    }

    //Create this ans node, and append each minHeap top to this node
    Node<int> *ans = new Node<int>(-1);
    //Temporary node to traverse ans list
    Node<int> *temp = ans;
    while(!minHeap.empty()){

            Node<int> *top = minHeap.top();
            minHeap.pop();
            temp->next = top;
            temp = temp->next;
            if(top->next)
                minHeap.push(top->next);
    }
    return ans->next;
}