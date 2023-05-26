#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

class Node {

    public:
        Node *left;
        Node *right;
        int data;

        Node(int data){
            this->left = NULL;
            this->right = NULL;
            this->data = data;
        }
};

Node *buildTree(Node *root,int data){

    if(root==NULL){
        Node *newNode = new Node(data);
        return newNode;
    }

    if(data > root->data)
        root->right = buildTree(root->right,data);
    else
        root->left = buildTree(root->left,data);

    return root;
}

void findMinMax(Node *root){

    Node *temp1 = root;
    Node *temp2 = root;

    while(temp1->right!=NULL){
            temp1 = temp1->right; 
    }       

    while (temp2->left!=NULL)
    {
        temp2 = temp2->left;
    }
    
    cout<<"Max Num is : "<<temp1->data<<endl;
    cout<<"Min Num is : "<<temp2->data<<endl; 
}

void inorderTraversal(Node *root){
    if(root==NULL)
        return;

    inorderTraversal(root->left);

    cout<<root->data<<" ";

    inorderTraversal(root->right);
}

void createTree(){

    Node *root = NULL;

    while(1){
        int data;
        cout<<"Enter the data : ";
        cin>>data;
        if(data==-1)
            break;
        root = buildTree(root,data);

    }

   findMinMax(root);
   cout<<"Inorder Traversal : ";
   inorderTraversal(root);


}

int main(){
    //10 5 7 2 8 15 13 20 -1
    createTree();
    return 0;
}