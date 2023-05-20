#include<iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

 void traverse(Node* root, int level,map<int,int>&mapp){
        
        if(root==NULL)
            return ;
            
        
        if(!mapp.count(level))
            mapp[level] = root->data;
        
        traverse(root->left, level+1,mapp);
        
        traverse(root->right,level+1,mapp);
        
    }
    
    vector<int> rightView(Node *root)
    {
       // Your Code here
        vector<int> ans;
        
        map<int,int> mapp;
        
        traverse(root,0,mapp);
        
        for(auto it = mapp.begin(); it!=mapp.end();it++)
            ans.push_back(it->second);
            
        return ans;
    
    }