#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

//Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};

// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree

string inorder(Node *root, unordered_map<string,int> &mapp,vector<Node*> &ans){
    
    if(!root)
        return "";
        
    string str = "(";
    str += inorder(root->left, mapp,ans);
    str += to_string(root->data);
    str += inorder(root->right,mapp,ans);
    str += ")";
    
    if(mapp[str]==1)
        ans.push_back(root);
    
    mapp[str]++;
    return str;
    
}

vector<Node*> printAllDups(Node* root)
{
    // Code here
    unordered_map<string, int> mapp;
    vector<Node*> ans;
    inorder(root,mapp,ans);
    // for(auto it: mapp){
    //     cout<<it.first<<" ";
    // }
    return ans;
}