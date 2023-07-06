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


void traverse(TreeNode<int> *root, vector<int> &inorder){

    if(!root)
        return;

    traverse(root->left,inorder);
    inorder.push_back(root->data);
    traverse(root->right,inorder);
    
}

void merge(vector<int> &tree1, vector<int> &tree2, vector<int> &finalTree){

    int i = 0,j=0;

    while(i<tree1.size() && j<tree2.size()){
        if(tree1[i] <= tree2[j])
            finalTree.push_back(tree1[i++]);
        else
            finalTree.push_back(tree2[j++]);
    }

    //Case 1 : if tree1 elements are left
    while(i<tree1.size())
        finalTree.push_back(tree1[i++]);
    
    //case 2
    while(j<tree2.size())
        finalTree.push_back(tree2[j++]);
}

TreeNode<int> *buildTree(vector<int> &finalTree, int start, int end){

    if(start > end)
        return NULL;

    int mid = (start + end)/2;
    TreeNode<int> *root = new TreeNode<int>(finalTree[mid]);
    
    root->left = buildTree(finalTree,start,mid-1);
    root->right = buildTree(finalTree,mid+1,end);

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int> tree1,tree2;
    traverse(root1,tree1);
    traverse(root2,tree2);
    vector<int>  finalTree;
    merge(tree1,tree2,finalTree);

    return buildTree(finalTree,0,finalTree.size()-1);    

}