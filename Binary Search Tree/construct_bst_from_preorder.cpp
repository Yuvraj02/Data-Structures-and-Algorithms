#include <iostream>
#include <vector>

using namespace std;

    template <typename T>
    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };


BinaryTreeNode<int> *insertNode(int &i, vector<int> &preorder,int mini, int maxi){

    if(i>=preorder.size())
        return NULL;
        
    if(preorder[i] < mini || preorder[i] > maxi)
        return NULL;
        

        BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(preorder[i++]);

        newNode->left = insertNode(i, preorder, mini, newNode->data);
        newNode->right = insertNode(i, preorder,newNode->data, maxi);

        
        return newNode;
    
    
}


BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.

    int mini = INT32_MIN;
    
    int maxi = INT32_MAX;
    int i = 0;
    return  insertNode(i, preorder, mini, maxi);

    // BinaryTreeNode<int> *root = NULL;
    // // BinaryTreeNode<int> *root = newNode;
    // for(int i = 0; i<preorder.size();i++){

    //         root = insertNode(root,preorder[i]);
    // }

    // return root;
}