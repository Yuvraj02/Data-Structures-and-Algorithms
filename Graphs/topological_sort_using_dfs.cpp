#include <iostream>
#include <unordered_map>
#include <list>
#include <vector> 
#include <stack>

using namespace std;

void dfs(int node, unordered_map<int,list<int>> &adj, vector<bool> &visited,
        stack<int> &s){
    
    visited[node] = true;

    for(auto neighbour : adj[node]){

        if(!visited[neighbour])
            dfs(neighbour,adj,visited,s);

    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    unordered_map<int,list<int>> adj;

    for(int i=0;i<e;i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v);

    stack<int> s;

    for(int i = 0 ;i < v; i++){
        if(!visited[i]){
            dfs(i,adj,visited,s);
        }

    }

    vector<int> topology;
    while(!s.empty()){
        topology.push_back(s.top());
        s.pop();
    }
    return topology;


}