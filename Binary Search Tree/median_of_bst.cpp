#include <iostream>
#include <vector>

using namespace std;

class Node {

    public:
        Node *left;
        Node *right;
        int data;

        Node(int data){
            this->left = NULL;
            this->right = NULL;
            this->data = data;
        }
};

void traverse(struct Node *root, vector<int> &inorder){
    if(!root)
        return ;
        
    traverse(root->left, inorder);
    inorder.push_back(root->data);
    traverse(root->right,inorder);
}

float findMedian(struct Node *root)
{
      //Code here
        vector<int> inorder;  
        //Step 1: Get inorder of the tree 
        traverse(root,inorder);
        //Step 2 : Get midean from the inorder
        if(inorder.size()&1){
            return inorder[inorder.size()/2];
        }else{
            int a = inorder[inorder.size()/2];
            int b = inorder[(inorder.size()/2) - 1];
            return (a + b)/2.0;
        }
}