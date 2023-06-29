#include <iostream>
using namespace std; 
 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Convert in Inorder Form
void convertToDLL(Node *root, Node* &prev, Node* &head){

    if(root==NULL)
        return ;

    convertToDLL(root->left,prev,head);

    if(prev==NULL)
        head = root;
    else{

        root->left = prev;
        prev->right = root;

    }
    
    prev = root;

    convertToDLL(root->right,prev,head);

 }
 
    Node * bToDLL(Node *root)
    {
        // your code here
        Node *head = NULL;
        Node *prev = NULL;
        convertToDLL(root,prev,head);
        
        return head;
    }