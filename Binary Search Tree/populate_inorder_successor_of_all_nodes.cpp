#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

    void reverseInorder(Node *root, Node* &prev){
        
        if(!root)
            return;
        
        reverseInorder(root->right,prev);
        
        root->next = prev;
        prev = root;
        
        reverseInorder(root->left,prev);
        
    }

    void populateNext(Node *root)
    {
        //code here
        Node *prev = NULL;
        reverseInorder(root,prev);
    }