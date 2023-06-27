#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

 vector<vector<int>> levelOrder(TreeNode* root) {

        if(root==NULL)
            return {};

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int> level;
        while(!q.empty()){

            TreeNode* front = q.front();
            q.pop();
            
            if(front==NULL){
                 ans.push_back(level);
                if(!q.empty()){
                    level.clear();
                    q.push(NULL);
                }
            }else{

                level.push_back(front->val);

                if(front->left){
                    q.push(front->left);
                }

                if(front->right){
                    q.push(front->right);
                }

            }

        }
    return ans;
    }