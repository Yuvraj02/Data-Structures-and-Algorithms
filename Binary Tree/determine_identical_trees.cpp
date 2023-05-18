#include <iostream>

using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

/*
Build a Tree here first : 

Node* buildTree(Node* root){

    //Complete this function

}

*/


    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2 == NULL)
            return true;
        
        if((r1==NULL && r2 != NULL) || (r1!=NULL && r2==NULL))
            return false;
            
        bool left = isIdentical(r1->left,r2->left);
        
        bool right = isIdentical(r1->right,r2->right);
        
        bool currVal = r1->data == r2->data;
        
        if(left && right && currVal)
            return true;
        else
            return false;
        
    }
