#include <iostream>
using namespace std;

class Node {
    public:
        Node  *left,*right;
        int data;

    Node(int data){
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

 Node *inorder(Node *root, int &K, int &i){
        
        if(!root)
            return root;
            
        //Go to right first because we are finding largest element
        //So going right first of BST means we are traversing in reverse
        //Hence decending order
        Node *right = inorder(root->right,K, i);
        
        i++;
        
        if(i==K)
            return root;
            
        Node *left = inorder(root->left, K, i);
        
        if(right!=NULL)
            return right;
        else
            return left;
        
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int i = 0;
        return inorder(root,K,i)->data;
    }
