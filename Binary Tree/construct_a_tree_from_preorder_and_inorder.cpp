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

 void findPosition(int in[],map<int,int> &nodeIndex,int n){
        
        for(int i=0;i<n;i++){
            nodeIndex[in[i]] = i;
        }
    }
    
    Node *solve(int &index, int in[], int pre[], int inorderStart, int inorderEnd,int n,map<int,int> &nodeIndex){
        
        if(index>=n || inorderStart > inorderEnd)
            return NULL;
            
        int element = pre[index++];
        Node *root = new Node(element);
        int position = nodeIndex[element];
        
        root->left = solve(index, in,pre,inorderStart,position-1,n,nodeIndex);
        root->right = solve(index, in, pre, position+1, inorderEnd,n,nodeIndex);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        map<int,int> nodeIndex;
        findPosition(in,nodeIndex,n);
        return solve(preOrderIndex,in,pre,0,n-1,n,nodeIndex);
        
    }