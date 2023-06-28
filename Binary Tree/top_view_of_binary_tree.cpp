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

  vector<int> topView(Node *root)
    {
        //Your code here
        pair<Node*, int> level = {root, 0};
        queue<pair<Node*,int>> q;
        map<int,int> mapp;
       
        q.push(level);
        
        while(!q.empty()){
            
            pair<Node*, int> front = q.front();
            q.pop();
            
            //{Node, level}
            Node *node = front.first;
            int currLevel = front.second;
            
            if(mapp[currLevel] == NULL)
                mapp[currLevel] = node->data;
            
            if(node->left){
                q.push({node->left, currLevel-1});
            }
            if(node->right){
                q.push({node->right,currLevel+1});
            }
            
        }
        vector<int> ans;
        for(auto i : mapp)
            ans.push_back(i.second);
            
        return ans;
    }
