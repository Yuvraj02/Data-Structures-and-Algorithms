#include<iostream>
#include <queue>

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

 
 bool check(Node *root)
    {
        //Your code here
        int leafLevel = -1;
        int level = 0;
        queue<Node* > q;
        q.push(root);
        q.push(NULL);
        
        
        while(!q.empty()){
            Node *front = q.front();
            q.pop();
            
            if(front==NULL){
                if(!q.empty()){
                    q.push(NULL);
                    level++;
                }
            }else{
                
                if(front->left==NULL && front->right==NULL){
                    if(leafLevel==-1){
                        leafLevel = level;
                    }else if(leafLevel != level){
                        return false;
                    }
                }
                
                if(front->left)
                    q.push(front->left);
                
                if(front->right)
                    q.push(front->right);
                
            }
            
        }
        return true;
    }