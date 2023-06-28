#include<iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

  vector <int> bottomView(Node *root) {
        // Your Code Here
        pair<Node*,int> p1 = {root,0};
        
        queue<pair<Node*, int>> q;
        q.push(p1);
        
        map<int,int> mapp;
        
        while(!q.empty()){
            
            pair<Node*,int> front = q.front();
            q.pop();
            
            Node *node = front.first;
            int currLevel = front.second;
            
            mapp[currLevel] = node->data;
            //If we go left side then we measure level in negative scale
            if(node->left){
                q.push({node->left, currLevel-1});
            }            
            
            if(node->right){
                q.push({node->right,currLevel+1});
            }
        }
        
        vector<int> ans;
        for(auto i : mapp){
            ans.push_back(i.second);
        }
        return ans;
    }