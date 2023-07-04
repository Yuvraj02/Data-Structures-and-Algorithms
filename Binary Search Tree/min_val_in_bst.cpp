#include <iostream>

using namespace std;

class Node{
    public:
        Node *left,*right;
        int data;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int minValue(Node* root) {
    // Code here
    
    if(!root)
        return -1;
    
    Node *temp = root;
    
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp->data;
}
