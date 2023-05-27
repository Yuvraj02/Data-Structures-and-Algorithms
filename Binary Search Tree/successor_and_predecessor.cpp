#include <iostream>

using namespace std;

class Node{

    public:
        Node *left;
        Node *right;
        int key;


};


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

       if(root==NULL)
            return;
        
        if(root->key == key){
            
            //Find Predecessor
            //Predecessor will be max of left subtree
            if(root->left){
                
                Node *temp = root->left;
                while(temp->right) temp = temp->right;
                
                pre = temp;
                
            }
            
            //Find Successor
            //Successor will be min of right sub tree
            if(root->right){
                Node *temp = root->right;
                
                while(temp->left)
                    temp = temp->left;
                    
                suc = temp;
            }
            
            return ;
        }
        
        if(key > root->key){
            
            pre = root;
            findPreSuc(root->right,pre,suc,key);
        }else{
            suc = root;
            findPreSuc(root->left,pre,suc,key);
        }

}