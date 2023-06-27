#include<iostream>

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

    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        // code here
        if(root==NULL)
            return;
            
        Node *left = root->left;
        Node *right = root->right;
        
        root->left = right;
        root->right = left;
        
        mirror(root->left);
        mirror(root->right);
}