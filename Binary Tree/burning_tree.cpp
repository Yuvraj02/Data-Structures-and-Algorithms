 #include<iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
}; 
 
 Node *findTarget(Node *root, map<Node*,Node*> &nodeToParent,int target){
        
        queue<Node*> q;
        q.push(root);
        
        nodeToParent[root] = NULL;
        
        Node *targ = NULL;
        while(!q.empty()){
            Node *front = q.front();
            
            if(front->data==target)
                targ = front;
            q.pop();
            
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
            
        }
        
        return targ;
        
    }
    
    int burnTree(Node *target, map<Node*,Node*> nodeToParent){
            map<Node*, bool> visited;
            queue<Node*> q;
            q.push(target);
            visited[target] = true;
            
            int ans=0;
            

            
            while(!q.empty()){
                
                int size = q.size();
                
                bool flag = false;
                
                for(int i=0;i<size;i++){
                    
                Node *currNode = q.front();
                
                q.pop();
                
                if(currNode->left && !visited[currNode->left]){
                    flag = 1;
                    q.push(currNode->left);
                    visited[currNode->left] = true;
                }            
                if(currNode->right && !visited[currNode->right]){
                    flag = 1;
                    q.push(currNode->right);
                    visited[currNode->right] = true;
                }    
                if(nodeToParent[currNode] && !visited[nodeToParent[currNode]]){
                    q.push(nodeToParent[currNode]);
                    visited[nodeToParent[currNode]] = true;
                    flag = 1;
                }

                }
                
                if(flag)
                    ans++;
                
            }
        return ans;
    }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        //Algo:
        //Step 1 : Map node to parent
        //Step 2 : Find Target Node
        //Step 3 : Burn tree
        map<Node*,Node*> nodeToParent;
       
        Node *targetNode = findTarget(root,nodeToParent,target);
        
        return burnTree(targetNode,nodeToParent);
    }