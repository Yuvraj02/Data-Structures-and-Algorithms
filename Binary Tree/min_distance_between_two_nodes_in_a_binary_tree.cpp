#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

Node *findAncestor(Node *root, int a, int b, int &d1, int &d2, int &dist,int level){
        
        if(root==NULL)
            return NULL;
        //If a found then set d1 to level of a
        if(root->data == a){
            d1 = level;
            return root;
        }
        
        if(root->data == b){
            d2 = level;
            return root;
        }
        
        Node *left = findAncestor(root->left, a, b, d1, d2, dist, level+1);
        Node *right = findAncestor(root->right, a,b, d1, d2, dist,level+1);
        
        if(left && !right){
            return left;
        }else if(!left && right){
            return right;
        }else if (left && right){
            dist = d1 + d2 - 2*level;
            return root;
        }else{
            return NULL;
        }
        return root;
    }
    
    int findLevel(Node *root, int level, int val){
        if(root==NULL)
            return 0;
        
        if(root->data == val)
            return level;
            
        int left = findLevel(root->left, level+1, val);
        int right = findLevel(root->right, level+1, val);
        
        return max(left,right);
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        int d1 = -1, d2 = -1, dist;
        
        Node *lca = findAncestor(root, a,b,d1,d2,dist,0);
        
        //If both d1 and d2 have been computed then simply return calculated distance between them
        if(d1!=-1 && d2!=-1)
            return dist;
        
        //Check for edge cases 
        //Case 1 : if a is ancestor of b
        if(d1!=-1){
            dist = findLevel(lca,0,b);
            return dist;
        }
        //Case 2 : if b is ancestor of a
        if(d2!=-1){
            dist = findLevel(lca,0,a);
            return dist;
        }
        
        return -1;
    }