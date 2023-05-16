#include <iostream>

using namespace std;

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

Node *buildTree(Node *root){

    cout<<"Enter the data: ";
    int data;
    cin>>data;

    if(data==-1)
        return NULL;

    root = new Node(data);

    cout<<"Going to the left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Going to the right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void preOrderTraversal(Node *root){

    if(root==NULL)
        return ;
    //Going left
    preOrderTraversal(root->left);
    
    cout<<root->data<<" ";

    preOrderTraversal(root->right);

}


int main(){

    Node *root = NULL;
    root = buildTree(root);
    /*
    --> 10 20 40 -1 -1 60 -1 -1 30 -1 -1

        10
      /  \
     20   30
    / \ 
   40  60
    */
    preOrderTraversal(root);
    return 0;
}