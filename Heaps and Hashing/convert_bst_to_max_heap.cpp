#include <iostream>
#include <vector>
 
 using namespace std;
 
 struct Node{
    int data;
    Node *left,*right;
 };
 
 void inorderTraversal(Node *root, vector<int> &inorder){
        
        if(root==NULL)
            return;
            
        inorderTraversal(root->left, inorder);
        
        inorder.push_back(root->data);
        
        inorderTraversal(root->right, inorder);
    }
  
    void preorder(Node *root, vector<int> &inorder, int &i){
        
        if(root==NULL)
            return;
            
        
        preorder(root->left, inorder, i);
        
        preorder(root->right, inorder, i);
        
        root->data = inorder[i++];
        
    }
  
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        vector<int> inorder;
        
        inorderTraversal(root,inorder);
        
        //Now store in preorder style
        int i = 0;
        preorder(root,inorder,i);
    }    