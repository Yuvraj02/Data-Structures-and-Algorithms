#include <iostream>
#include <vector>


/*
  Intuition 1:  The intuition is to traverse the tree and once the traversal reaches the target then simply print nodes which are in vertical direction
    ->The second type of nodes are in the other subtree
    ->For that we have to come one step back go to right or left subtree and again get the nodes downwards

  Intution 2:
    Perform level order traversal and keep track of parent
    Then Perform BFS from the target node and push it's left, right and parent to the queue and increment counter
    Each time we add left,right and parent to the queue the counter increments by 1 representing the distance from the
    current node
    When this counter==k then stop, by this time we have all the nodes which are at k distance from the target node
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

    void getDownNodes(TreeNode* root, int k, vector<int> &ans){
        if(!root)
            return ;
        if(k==0){
            ans.push_back(root->val);
                return;
        }

        getDownNodes(root->left,k-1,ans);
        getDownNodes(root->right,k-1,ans);
    }

    int getNodes(TreeNode* root,TreeNode *target, vector<int> &ans,int k){
        
        //Means target not found
        if(!root)
            return -1;

        if(root->val == target->val){
            getDownNodes(root,k,ans);
            return 0;
        }

        int left = getNodes(root->left, target,ans,k);

        if(left!=-1){
            if(left+1==k){
                //Means this ancestor is at K distance from current node
                ans.push_back(root->val);
            }else{
                //(k-left) is the distance of current ancestor from the target node
                //and - 2 because we are going in right subtree, so the element is 2 distance
                //away from the target (1 (root node) + 1 (the node on which we will go)) = 2
                getDownNodes(root->right,k-left-2,ans);
            }
            return left+1;
        }
        int right = getNodes(root->right,target,ans,k);   

        if(right!=-1){
            if(right+1==k){
                ans.push_back(root->val);
            }else{
                //Go to left subtree and get down nodes
                getDownNodes(root->left,k-right-2,ans);
            }
            return right+1;
        }

        //If both children were -1 that means it's a leaf node, so return -1;
        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        getNodes(root,target,ans,k);
        return ans;
    }
};