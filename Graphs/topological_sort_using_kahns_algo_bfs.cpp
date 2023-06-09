#include <iostream>
#include <unordered_map>
#include <list>
#include <vector> 
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    vector<int> inDegree(n,0);
    for(int i = 0; i<e;i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        inDegree[v]++;
    } 
    
    vector<int> ans;
    queue<int> q;
    for(int i = 0; i<n;i++){

        if(inDegree[i]==0)
            q.push(i);
    }
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto i : adj[front]){
            inDegree[i]--;
            
            if(inDegree[i]==0){
                q.push(i);
            }

        }

    }

    return ans;
    
}