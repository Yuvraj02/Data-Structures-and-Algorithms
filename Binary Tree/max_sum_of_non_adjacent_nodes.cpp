#include<iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

pair<int,int> sum(Node *root){
        
        if(root==NULL)
            return {0,0};
        
        pair<int,int> left = sum(root->left);
        pair<int,int> right = sum(root->right);
        
        pair<int,int> res;
        //Include
        res.first = root->data + left.second + right.second;
        
        //Exclude
        res.second = max(left.first,left.second) + max(right.first,right.second);
        
        return res;
    }
    
    int getMaxSum(Node *root) 
    {
        // Add your code her
        //<include, exclude>
        pair<int,int> ans = sum(root);
        
        return max(ans.first,ans.second);
    }