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
        queue<pair<Node*, int>> q;
        
        map<int, int> mapp;
        
        q.push({root,0});
        
        while(!q.empty()){
            
            pair<Node*, int> temp = q.front();
            Node *front = temp.first;
            int hd = temp.second;
            q.pop();
            
            if(!mapp.count(hd))
                mapp[hd] = front->data;
                
            if(front->left)
                q.push({front->left,hd-1});
                
            if(front->right)
                q.push({front->right,hd+1});
            
        }
        
        vector<int> ans;
        auto it = mapp.begin();
        while(it!=mapp.end()){
            ans.push_back(it->second);
            it++;
        }
        
        return ans;
    }