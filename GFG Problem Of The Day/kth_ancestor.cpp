#include <iostream>

using namespace std;


struct Node
{
	int data;
	struct Node *left, *right;
};

Node *traverse(Node *root, int &k, int node){
        
    if(!root)
        return NULL;
    
    if(root->data == node)
        return root;
    
    Node *left = traverse(root->left, k, node);
    Node *right = traverse(root->right, k, node);
    
    if(left && !right){
        
        k--;
        if(k==0)
            return root;
        
        return left;
    }else if(!left && right){
        k--;
        if(k==0)
            return root;
        
        return right;
    }
    
    return NULL;
    
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ancestor = traverse(root,k,node)->data;
    if(ancestor == node)
        return -1;
    else
        return ancestor;
}