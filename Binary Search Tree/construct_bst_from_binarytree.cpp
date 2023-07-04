#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node{
    public:
        Node *left,*right;
        int data;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void traverse(Node *root){
    if(!root)
        return ;

    traverse(root->left);
    cout<<root->data<<" ";
    traverse(root->right);
}

void traverse(Node *root,vector<int> &inorder){
    if(!root)
        return ;

    traverse(root->left,inorder);
    inorder.push_back(root->data);
    traverse(root->right,inorder);
}

Node *convertToBST(vector<int> &inorder, int start, int end){

    //IMP base case
    if(start > end){
        return NULL;
    }

    int mid = (start+end)/2;

    Node *root = new Node(inorder[mid]);

    root->left = convertToBST(inorder,start,mid-1);
    root->right = convertToBST(inorder,mid+1,end);

    return root;
}

int main(){
    
    //Constructing a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    vector<int> inorder;

    traverse(root,inorder);
    //Sort to get inorder of BST
    sort(inorder.begin(),inorder.end());

    Node *bstRoot = convertToBST(inorder,0,inorder.size()-1);
    
    traverse(bstRoot);

    return 0;
}