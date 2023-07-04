#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Node{
    public:
        Node *left,*right;
        int data;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void storeNodes(Node *root, unordered_set<int> &allNodes, unordered_set<int> &leafNode){

    
    if(root==NULL)
        return ;
        
    if(root->left==NULL && root->right==NULL){
        leafNode.insert(root->data);
        return ;
    }
    
    allNodes.insert(root->data);
    
    storeNodes(root->left, allNodes,leafNode);
    storeNodes(root->right, allNodes, leafNode);
}

bool isDeadEnd(Node *root)
{
    
    //We have to check, if there exists a leaf node x which has nodes x+1 and x-1 in bst, then it's
    //a node with a dead end
    unordered_set<int> allNodes, leafNodes;
    //Add 0 for a case where 1 presents at leaf 
    allNodes.insert(0);
    //Insert all nodes to their respective sets
    storeNodes(root,allNodes,leafNodes);
    
    //Now traverse all leaf nodes and check if there exists x+1 and x-1 nodes of each leaf node
    for(auto i : leafNodes){
        //If exists such node, then it means, the BST has a dead end
        if(allNodes.find(i+1) != allNodes.end() &&
           allNodes.find(i-1) != allNodes.end())
                return true;
    }
    
    return false;
    
}