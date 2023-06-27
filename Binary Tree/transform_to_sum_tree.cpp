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


int sumTree(Node *root){
        
        if(root==NULL)
            return 0;
            
        if(!root->left && !root->right){
            int val = root->data;
            root->data = 0;
            return val;
        }            
        int ls = sumTree(root->left);
        int rs = sumTree(root->right);
        
        int rootVal = root->data;
        root->data = ls + rs;
        
        return rootVal + root->data;
        
}
    
void toSumTree(Node *node)
{
        // Your code here
    sumTree(node);
}