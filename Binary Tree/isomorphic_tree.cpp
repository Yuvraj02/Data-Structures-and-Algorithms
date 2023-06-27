#include<iostream>

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

 
bool isIsomorphic(Node *root1,Node *root2)
{
    //If both nodes are null then it means we have reached correctly so return true
    if(root1==NULL && root2==NULL)
        return true;
        
    // Either of these nodes are null and the other is not null then it's not properly isomorphic
    if(root1 == NULL || root2==NULL)
        return false;
        
    //If the data inside them is not same that means it's not similar
    if(root1->data != root2->data)
        return false;
        
    return (isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right) || 
            isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right, root2->left));
}