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


void inorderTraversal(TreeNode<int> *root, vector<int> &inorder){

    if(root==NULL)
        return;

    inorderTraversal(root->left, inorder);

    inorder.push_back(root->data);

    inorderTraversal(root->right, inorder);

}

TreeNode<int> *buildTree(int start, int end, vector<int> &inorder){

    if(start > end)
        return NULL;

    int mid = (start + end)/2;
    TreeNode<int> *root = new TreeNode<int>(inorder[mid]);
    root->left = buildTree(start, mid-1, inorder);
    root->right = buildTree(mid+1, end, inorder);

    return root;

}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int> inorder1;
    vector<int> inorder2;

    inorderTraversal(root1, inorder1);
    inorderTraversal(root2, inorder2);
    vector<int> finalInorder;
    //Merge Two Sorted Arrays

    int i = 0,j=0;
    while(i<inorder1.size() && j < inorder2.size()){

        if(inorder1[i] <= inorder2[j]){
            finalInorder.push_back(inorder1[i++]);
        }else{
            finalInorder.push_back(inorder2[j++]);
        }
    }
    //Rest of the elements
    while(i<inorder1.size()){
        finalInorder.push_back(inorder1[i++]);
    }

    while(j<inorder2.size()){
        finalInorder.push_back(inorder2[j++]);
    }

    return buildTree(0, finalInorder.size()-1, finalInorder);
}