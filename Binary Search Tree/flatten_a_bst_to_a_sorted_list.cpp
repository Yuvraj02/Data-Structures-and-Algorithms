#include <iostream>
#include <vector> 

using namespace std;

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };


void inorder(TreeNode<int> *root,vector<int> &nodes){

    if(root==NULL)
        return ;
    
    inorder(root->left,nodes);

    nodes.push_back(root->data);

    inorder(root->right,nodes);

}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here

    vector<int> nodes;
    inorder(root,nodes);

    TreeNode<int> *newRoot = new TreeNode<int>(nodes[0]);
    TreeNode<int> *curr = newRoot;

    for(int i = 1; i <nodes.size();i++){

        TreeNode<int> *newRoot = new TreeNode<int>(nodes[i]);
        curr->right = newRoot;
        curr = curr->right;
    }

return newRoot;
    // for(auto i : nodes)
    //     cout<<i->data<<" ";

}