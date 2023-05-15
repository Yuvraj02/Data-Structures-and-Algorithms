#include <iostream>
#include <vector>

using namespace std;

class Node { 
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


Node *buildTree (Node *root){

cout<<"Enter Value : ";
int data;
cin>>data;
cout<<endl;

root = new Node(data);

if (data==-1)
    return NULL;

cout<<"Enter the Data to the left of "<<data<<". ";
root->left = buildTree(root->left);
cout<<"Enter the Data to the right of "<<data<<". ";
root->right = buildTree(root->right);    
    return root;
}

int main(){

    Node *root = NULL;

    root = buildTree(root);    

    return 0;
}