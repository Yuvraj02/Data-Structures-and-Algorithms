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
    
    pair<int,int> diam(Node *root){
        
        if(root==NULL)
            return {0,0};
            
        
        pair<int,int> leftDiam = diam(root->left);
        pair<int,int> rightDiam = diam(root->right);
        
        int op1 = leftDiam.first;
        int op2 = rightDiam.first;
        
        int op3 = leftDiam.second + rightDiam.second + 1;
        
        pair<int,int> ans;
        ans.first = max({op1,op2,op3});
        ans.second = max(leftDiam.second,rightDiam.second) + 1;
        
        return ans;
    }
    
    int solve(Node* root){
        
        if(root==NULL)
            return 0;
            
        int left =  solve(root->left);
        
        int right = solve(root->right);
        
        int leftRight = 1 + (height(root->left) + height(root->right)) ;

    return max({left,right,leftRight});
    }
    
    int diameter(Node* root) {
        // Your code here
        return diam(root).first;
    }
