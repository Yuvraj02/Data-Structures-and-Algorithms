   #include <iostream>

   using namespace std;

   class Node {
    public:
        Node *left,*right;
        int key;
   };
   
    /*
        If current root is greater than key, store this and then go to left as this
        as it might be a successor
    */

    void findSuc(Node *root,Node* &suc, int key){
        
        if(root==NULL)
            return ;

        if(root->key > key){
            suc = root;
            findSuc(root->left, suc,key);
        }else{
            findSuc(root->right, suc,key);
        }
        
    }
    
    /*
        if current root is smaller than key, then store it and got to right
        as it might be a predecessor.

    */
    void findPre(Node *root, Node* &pre, int key){
        
        if(root==NULL)
            return;

        if(root->key >= key){
            findPre(root->left, pre, key);
        }else{
            //A Predecessor can't be itself so store only when it's less    
            if(root->key < key)
                pre = root;
    
            findPre(root->right,pre, key);
        }
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
       findSuc(root,suc,key);
       findPre(root,pre,key);
    }