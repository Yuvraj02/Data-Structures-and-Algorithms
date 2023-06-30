#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

 string serialize(TreeNode* root) {
        if(root==NULL)
            return "";

        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){

            TreeNode *front = q.front();
            q.pop();
            
            if(front==NULL){
                str += "#,";
            }else{
            
            str+=to_string(front->val) + ",";
            if(front->left){
                q.push(front->left);
            }else{
                q.push(NULL);
            }

            if(front->right){
                q.push(front->right);
            }else{
                q.push(NULL);
            }
         }
        }
        return str;
    }

    TreeNode* deserialize(string data) {
        
        if(data.size()==0)
            return NULL;

        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *front = q.front();
            q.pop();

            //Get Left Node
            getline(s,str,',');
            if(str=="#"){
                front->left=NULL;
            }else{
                TreeNode *left = new TreeNode(stoi(str));
                front->left = left;
                q.push(left);
            }

            //Get Right Node
            getline(s,str,',');
            if(str=="#"){
                front->right = NULL;
            }else{
                TreeNode *right = new TreeNode(stoi(str));
                front->right = right;
                q.push(right);
            }
        }   

        return root;

    }