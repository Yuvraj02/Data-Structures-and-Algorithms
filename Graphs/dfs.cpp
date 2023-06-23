#include <iostream>
#include <unordered_map>
#include<list>
#include <vector>

using namespace std;


void dfs(vector<int> &component, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited, int node){

    component.push_back(node);
    visited[node] = true;

    for(auto i : adj[node]){
        if(!visited[i])
            dfs(component, adj, visited, i);
    }

}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,list<int>> adj;

    for(int i = 0; i < E; i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    vector<vector<int>> ans;

    for(int i=0;i<V;i++){

        if(!visited[i]){
            vector<int> component;
            dfs(component,adj,visited,i);
            ans.push_back(component);
        }

    }

    return ans;

}