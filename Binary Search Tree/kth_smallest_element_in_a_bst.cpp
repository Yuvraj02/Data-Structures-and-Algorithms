#include <iostream>
using namespace std;

class Node {
    public:
        Node  *left,*right;
        int data;

    Node(int data){
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

int solve(Node* root, int k, int &i){
    if(root==NULL)
        return -1;

    //Go to right
    int left = solve(root->right, k, i);

    if(left!=-1)
        return left;

    //N
    i++;
    if(i==k)
        return root->data;

    //L
        return solve(root->left, k, i);
}

int KthLargestNumber(Node* root, int k) 
{
    // Write your code here.
    int i = 0;
    return solve(root,k,i);
}
