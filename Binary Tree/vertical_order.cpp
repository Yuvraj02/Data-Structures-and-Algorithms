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

  vector<int> verticalOrder(Node *root)
    {
        //Your code here
        
        queue<pair<Node*, int>> q;
        
        map<int,vector<int>> mapp;

        vector<int> ans;        
        int numLine = 0;
        q.push({root,numLine});
        
        while(!q.empty()){
            
            pair<Node*, int> temp = q.front();
            
            Node *front = temp.first;
            int line = temp.second;
            q.pop();
            
            mapp[line].push_back(front->data);
            
            if(front->left){
                q.push({front->left, line-1});
            }
            
            if(front->right){
                q.push({front->right,line+1});
            }
            
        }
        
        auto it = mapp.begin();
        
        while(it!=mapp.end()){
            
            for(int i : it->second){
                ans.push_back(i);
            }
            it++;
        }
        
        return ans;
    }