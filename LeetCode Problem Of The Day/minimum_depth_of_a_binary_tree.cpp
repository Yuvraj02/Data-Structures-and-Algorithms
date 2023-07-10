#include <iostream>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
 
 
 int getDepth(TreeNode* root){
        if(root==NULL)
        return 1e9;

       if(!root->left && !root->right)
        return 0;

        int left = 1 + getDepth(root->left);
        int right = 1 + getDepth(root->right);

        return min(left,right);
    }
    int minDepth(TreeNode* root) {
       if(!root)
        return 0;
        
        return getDepth(root)+1;
    }