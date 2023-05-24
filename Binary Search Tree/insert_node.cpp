#include <iostream>

using namespace std;

/*
        10
       /  \
      7    15
     / \   / \
    3   8 13  18

Preorder = 3 7 8 10 13 15 18
*/

class Node {
    public:
        Node *left;
        Node *right;
        int data;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node *insertNode(Node *root, int data){

    if(root==NULL){
        Node *newNode = new Node(data);
        return newNode;
    }

    if(data>root->data)
        root->right = insertNode(root->right,data);
    else
        root->left = insertNode(root->left,data);

    return root;
}

void inOrderTraversal(Node *root){

    if(root==NULL)
        return;
    
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void takeInput(){

    Node *root=NULL;

    int data;
    while (1)
    {
        cout<<"Enter Node Data : ";
        cin>>data;
        if(data==-1)
            break;
        
        root = insertNode(root,data);

    }
    
    cout<<endl;
    inOrderTraversal(root);
}

int main(){

    takeInput();
    
    return 0;
}