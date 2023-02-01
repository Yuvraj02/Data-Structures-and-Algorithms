#include <iostream>

using namespace std;


class Node{

    public:
        int val;
        Node *next_node;

    //Constructor
    Node(int val){
        this->next_node = nullptr;
        this->val = val;
    }

};


int main(){

    Node *node1 = new Node(10);
    cout<<node1->val;

    return 0;
}