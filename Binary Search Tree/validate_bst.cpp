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
 

bool validate(TreeNode* root, long minVal, long maxVal){
        if(!root)
            return true;

        if(root->val <= minVal || root->val >= maxVal)
            return false;
        
        bool left = validate(root->left, minVal, root->val);
        bool right = validate(root->right, root->val,maxVal);

        return (left && right);

    }

    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right)
            return true;

        return validate(root,LONG_MIN,LONG_MAX);
    } 