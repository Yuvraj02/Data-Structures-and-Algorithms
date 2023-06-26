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

 //Function to check if S is a subtree of tree T.
    bool isIdentical(TreeNode *root1, TreeNode *root2){
        
        //If both are null return true because we have reached till end successfully
        if(root1==NULL && root2 == NULL)
            return true;
        
        //If either of them is NULL and one is not null then it's not a subtree
        if(root1==NULL || root2==NULL)
            return false;
            
        return (root1->val==root2->val
                && isIdentical(root1->left,root2->left)
                && isIdentical(root1->right,root2->right));    
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(subRoot==NULL)
            return true;
        
        if(root==NULL)
            return false;

        if(isIdentical(root,subRoot))
            return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);

    }