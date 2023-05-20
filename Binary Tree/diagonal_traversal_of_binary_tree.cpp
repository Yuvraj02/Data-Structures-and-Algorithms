#include<iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

void traverseDiagonal(Node *root, int dd, map<int,vector<int>>& mapp){
    
    if(root==NULL)
        return;
        
    mapp[dd].push_back(root->data);
    
    traverseDiagonal(root->left,dd+1,mapp);
    
    traverseDiagonal(root->right,dd,mapp);
    
}
 

vector<int> diagonal(Node *root)
{
   // your code here

    map<int, vector<int> > mapp;
    
    vector<int> ans;
    
    traverseDiagonal(root,0,mapp);
    
    for(auto vect = mapp.begin();vect!=mapp.end();vect++){
        
        for(auto i : vect->second){
            ans.push_back(i);
        }
        
    }
   
   return ans;
   
}