#include<iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

void leftTraversal(Node *root, vector<int> &ans){
        
        if(root==NULL || (root->right==NULL && root->left==NULL))
            return ;
           
        ans.push_back(root->data);    
        if(root->left)
            leftTraversal(root->left,ans);
            
        else{
            leftTraversal(root->right,ans);
        }
        
    }
    
    void leafTraversal(Node *root, vector<int> &ans){
        
        if(root==NULL)
            return ;
            
        if(root->left==NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        
        leafTraversal(root->left,ans);
        
        leafTraversal(root->right,ans);
        
    }
    
    void traverseRight(Node *root, vector<int> &ans){
        
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return ;
            
        
        if(root->right){
            traverseRight(root->right,ans);
        }else{
            traverseRight(root->left,ans);
        }
        
        //While traversing right push in the end because we are coming in reverse
        ans.push_back(root->data);
        
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        
        if(root==NULL)
            return {};
        
        vector<int> ans;
        
        ans.push_back(root->data);
        leftTraversal(root->left,ans);
        leafTraversal(root->left,ans);
        leafTraversal(root->right,ans);
        traverseRight(root->right,ans);
    
        return ans;
    }