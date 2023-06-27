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

    int findPos(int element, int in[], int inorderStart,int inorderEnd){
        
        for(int i=inorderStart; i<=inorderEnd;i++){
            if(in[i]==element)
                return i;
        }
        return -1;
    }

    Node *solve(int &index, int in[], int post[], int inorderStart,int inorderEnd,int n,map<int,int> &nodeIndex){
        
        if(index < 0 || inorderStart > inorderEnd)
            return NULL;
            
        int element = post[index--];
        Node *root = new Node(element);
        int pos = nodeIndex[element];
        
        root->right = solve(index,in,post,pos+1, inorderEnd,n,nodeIndex);
        root->left = solve(index,in,post,inorderStart, pos-1,n,nodeIndex);
        
        return root;
        
    }

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postIndex = n-1;
    
    map<int,int> nodeIndex;
    findPosition(in,nodeIndex,n);
    
    return solve(postIndex,in,post,0,n-1,n,nodeIndex);
}