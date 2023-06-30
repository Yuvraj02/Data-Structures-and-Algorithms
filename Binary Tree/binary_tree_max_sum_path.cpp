#include <iostream>

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
  int maxSum(TreeNode *root, int &maxVal){

        if(root==NULL)
            return 0;

        //If the path is negative then we return 0 instead
        int leftSum = max(0,maxSum(root->left,maxVal));
        int rightSum = max(0,maxSum(root->right, maxVal));

        maxVal = max(maxVal, root->val + leftSum + rightSum);

        return root->val + max(leftSum,rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxVal = INT32_MIN;
        maxSum(root,maxVal);
        return maxVal;
    }