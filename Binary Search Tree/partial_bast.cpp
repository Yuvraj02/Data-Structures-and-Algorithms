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

bool validate(Node *root, int min, int max){

    if(root==NULL)
        return true;

    if(root->data >= min && root->data <= max){

        bool left = validate(root->left, min,root->data);
        bool right = validate(root->right, root->data, max);

        return left && right;
    }else{
        return false;
    }

}

bool validateBST(Node *root) {
    // Write your code here
    validate(root,INT32_MIN,INT32_MAX);
}