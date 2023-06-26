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

 TreeNode* invertTree(TreeNode* root) {
        
        if(root==NULL)
            return NULL;

        //Take left and right nodes of tree
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        //Invert the nodes
        root->left = right;
        root->right = left;

        //Perform same operation on rest of the tree
        invertTree(root->left);
        invertTree(root->right);

        return root;

}