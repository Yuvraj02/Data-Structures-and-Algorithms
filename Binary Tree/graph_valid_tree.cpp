#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;



bool dfs(int node, int parent, unordered_map<int,list<int>> &adj, vector<bool> &visited){

    visited[node] = true;

    for(auto nbr : adj[node]){
        if(visited[nbr] && nbr!=parent)
            return true;

        if(!visited[nbr]){

            if(dfs(nbr,node,adj,visited))
                return true;
        }
    }

    return false;
}


bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    // write your code here
    unordered_map<int,list<int>> adj;

    for(int i =0;i<m;i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<bool> visited(n,false);

    int components = 0;
    bool hasCycle = false;
    for(int i = 0; i<n;i++){
      if (!visited[i]) {
        components++;
        hasCycle = dfs(i, -1, adj, visited);
        if(hasCycle)
            break;
      }
    }
    //If graph has a cycle or more than 1 component then it's not a tree
    if(hasCycle || components>1)
        return false;
    
    return true;

}