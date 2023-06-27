#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

 vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root==NULL)
            return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> nodes;
        stack<vector<int>> s;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){

            TreeNode *front = q.front();
            q.pop();

            if(front==NULL){
                s.push(nodes);
                if(!q.empty()){
                    q.push(NULL);
                    nodes.clear();
                }
            }else{

                nodes.push_back(front->val);

                if(front->left){
                    q.push(front->left);
                }

                if(front->right)
                    q.push(front->right);
            }

        }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }   
    return ans;
    }