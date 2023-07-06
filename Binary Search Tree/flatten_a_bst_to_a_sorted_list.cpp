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

//Another approach

void convertToLL(TreeNode<int> *curr, TreeNode<int> *&prev,TreeNode<int>* &head){
    if(!curr)
        return ;

    convertToLL(curr->left,prev,head);

    if(prev==NULL)
        head = curr;
    else{
        prev->right = curr;
        curr->left = NULL;
    }
    
    prev = curr;
    convertToLL(curr->right,prev,head);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    TreeNode<int> *head=NULL;
    TreeNode<int> *prev = NULL;
    convertToLL(root,prev,head);
    return head;
}