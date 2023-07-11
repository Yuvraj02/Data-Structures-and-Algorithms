#include <iostream>
#include <vector>


/*
    The intuition is to traverse the tree and once the traversal reaches the target then simply print nodes which are in vertical direction
    ->The second type of nodes are in the other subtree
    ->For that we have to come one step back go to right or left subtree and again get the nodes downwards
*/

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:

    void getDownNodes(TreeNode *root,vector<int> &ans, int k){
        if(!root)
            return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }

        getDownNodes(root->left,ans,k-1);
        getDownNodes(root->right,ans,k-1);
    }

    int getNodes(TreeNode *root, TreeNode *target, int k,vector<int> &ans){
        if(!root){
            return -1;
        }
        if(root->val == target->val){
            //Then get all down nodes and return 0;
            getDownNodes(root,ans,k);
            return 0;
        }

        int left = getNodes(root->left, target, k,ans);

        if(left!=-1){
            //If left + 1 equals to K,that means current root is neighbour
            if(left+1==k){
                ans.push_back(root->val);
            }else{
                //Else go to the right subtree of this ancestor and get elements
                //If we go to the right subtree, the k value will change
                //Because the node at right subtree is k-(left or right)-2 distance apart
                getDownNodes(root->right, ans,k-left-2);
            }
            //
            return left+1;
        }

        int right = getNodes(root->right, target,k,ans);
        //Do the same for right subtree as above
        if(right!=-1){
                if(right+1==k)
                    ans.push_back(root->val);
                else
                    getDownNodes(root->left,ans,k-right-2);
            return right+1;
        }
        return -1;
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        //getDownNodes(target,ans,k);
        getNodes(root,target,k,ans);
        return ans;
    }
};