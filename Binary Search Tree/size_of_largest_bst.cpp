#include <iostream>

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

class info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info traverseTree(TreeNode<int>* root, int &maxSize){
    
    if(!root)
      return {INT32_MIN, INT32_MAX, true,0};

    info leftTree = traverseTree(root->left, maxSize);
    info rightTree = traverseTree(root->right, maxSize);

    //This will hold values from both subtrees
    info currNode;
    //This is the total size of the tree upto current node
    currNode.size = leftTree.size + rightTree.size + 1;

    //Get Min and Max value for curr node, so that we can compare and check whether the value
    //of current node lies within the correct range
    //Minimum value should be minimum of left subtree
    //and maximum value should be maximum of right subtree
    //if this is not the case, then when we include curr node, it's not a BST
    currNode.mini = min(root->data, leftTree.mini);
    currNode.maxi = max(root->data, rightTree.maxi);
    
    //Check if the curr node is in the correct place
    if(leftTree.isBST && rightTree.isBST &&(root->data > leftTree.maxi && root->data < rightTree.mini))
        currNode.isBST = true;
    else
        currNode.isBST = false;
    
    if(currNode.isBST)
        maxSize = max(maxSize,currNode.size);
    return currNode;
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxSize = 0;
    traverseTree(root,maxSize);
    return maxSize;

}