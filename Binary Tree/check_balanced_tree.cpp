#include <iostream>
#include <utility>
#include <algorithm>

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

    // Function to return the diameter of a Binary Tree.
    
    int height(Node *root){
        
        if(root==NULL)
            return 0;
            
        int left = 1 + height(root->left);
        
        int right = 1 + height(root->right);
        
        return max(left,right);
        
    }
    
   pair<bool,int> checkBalanceFast(Node *root){
            
            if(root==NULL)
                return {true,0};
            
            pair<bool,int> left = checkBalanceFast(root->left);
            
            pair<bool,int> right = checkBalanceFast(root->right);
            
            bool leftTree = left.first;
            bool rightTree = right.first;
            
            bool diff = abs(left.second - right.second) <=1;
            
            pair<bool,int> ans;
            ans.second = max(left.second,right.second) + 1;
            
            if(leftTree && rightTree && diff){
                ans.first = true;
            }else{
                ans.first = false;
            }
            return ans;
    }
    
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        // if(root==NULL)
        //     return true;
            
        // bool left = isBalanced(root->left);
        
        // bool right = isBalanced(root->right);
        
        // bool diff = abs(height(root->left) - height(root->right)) <=1;
        
        // if(left && right && diff)
        //     return true;
        // else
        //     return false;
        return checkBalanceFast(root).first;
    }
