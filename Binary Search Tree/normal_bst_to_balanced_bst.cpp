#include <iostream>
#include <vector>

using namespace std;
    template <typename T>
    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };


void inorderTraversal(TreeNode<int>* root, vector<int> &inorder){

    if(root==NULL)
        return;

    inorderTraversal(root->left, inorder);

    inorder.push_back(root->data);

    inorderTraversal(root->right,inorder);
}

TreeNode<int>* balanceTree(int start, int end, vector<int> &inorder){

    if(start > end)
        return NULL;
    
    int mid = (start+end)/2;
    TreeNode<int> *rootNode = new TreeNode<int>(inorder[mid]);

    rootNode->left = balanceTree(start, mid-1, inorder);

    rootNode->right = balanceTree(mid+1, end, inorder);

    return rootNode;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> inorder;
    inorderTraversal(root, inorder);
    
    int n = inorder.size()-1;
    return balanceTree(0, inorder.size()-1, inorder);


}
