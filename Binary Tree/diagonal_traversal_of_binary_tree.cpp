#include<iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

void diagTraversal(Node *root, map<int,vector<int>> &mapp, int level){
    
    if(root==NULL)
        return;
    
    mapp[level].push_back(root->data);
    
    diagTraversal(root->left,mapp,level+1);
    diagTraversal(root->right,mapp,level);
}

vector<int> diagonal(Node *root)
{
   // your code here
    map<int,vector<int>> mapp;  
    
    diagTraversal(root,mapp,0);
 
    vector<int> ans;
    
    for(auto i : mapp){
        for(auto j : i.second)
            ans.push_back(j);
    }
   return ans;
   
}