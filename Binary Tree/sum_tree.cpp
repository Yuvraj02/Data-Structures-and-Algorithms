#include <iostream>
#include <utility>

using namespace std;

//Build Tree first

//  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; 

// Should return true if tree is Sum Tree, else false

    pair<bool,int> isSumTreeFast(Node *root){
        
        if(root==NULL)
            return {true,0};
            
        if(root->left==NULL && root->right==NULL)
            return {true,root->data};
            
        pair<bool,int> left = isSumTreeFast(root->left);
        pair<bool,int> right = isSumTreeFast(root->right);
        
        bool leftTree = left.first;
        
        bool rightTree = right.first;
        
        bool sum = (left.second + right.second) == root->data;
        
        pair<bool,int> ans;
        ans.second = 2*root->data ;
        
        if(leftTree && rightTree && sum)
            ans.first = true;
        else
            ans.first = false;
            
        return ans;
    }
    
    bool isSumTree(Node* root)
    {
         
        return isSumTreeFast(root).first;
    }