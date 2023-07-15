 #include <iostream>
 
 using namespace std;
 
 struct Node{
    int data;
    Node *left,*right;
 };

 int count(struct Node* root){
        if(!root)
            return 0;
            
        int ans = 1 + count(root->left) + count(root->right);
        
        return ans;
            
    }
    
    bool isCBT(struct Node* root, int index, int nodes){
        
        if(root==NULL)
            return true;
        
        if(index >= nodes)
            return false;
            
        bool left = isCBT(root->left, 2*index+1, nodes);
        bool right = isCBT(root->right, 2*index+2, nodes);
        
        return left && right;
    }
    
    bool maxOrder(struct Node *root){
        
        if(!root->left && !root->right)
            return true;
        
        if(!root->right){
            
            return (root->data > root->left->data
                    && maxOrder(root->left));
        }
        
        
        return (root->data > root->left->data && root->data > root->right->data
                    && maxOrder(root->left)
                    && maxOrder(root->right));
    }
    
    bool isHeap(struct Node* tree) {
        // code here
        int nodes = count(tree);
        if(isCBT(tree,0,nodes) && maxOrder(tree))
            return true;
        
        return false;
        