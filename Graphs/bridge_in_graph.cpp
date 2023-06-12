#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(int node, unordered_map<int,list<int>> &adj,vector<int> &low, vector<int> &disc, int &timer,
            vector<vector<int>> &result,vector<bool> &visited,int parent){
        
        visited[node] = true;

        disc[node] = low[node] = timer++;

        for(auto neighbour : adj[node]){

            if(parent==neighbour)
                continue;
            
            if(!visited[neighbour]){
                dfs(neighbour,adj,low,disc,timer,result,visited,node);
                //After returing from the call, update the low of current
                low[node] = min(low[node], low[neighbour]);

                //Check if the edge is bridge or not
                if(low[neighbour] > disc[node]){
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(neighbour);
                    result.push_back(ans);
                }


            }else{ //If the neighbour is already visited, and is not a parent then it's a Back Edge
                //Back Edge case
                low[node] = min(low[node], disc[neighbour]);
            }

        }
            
    
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int n, int e) {
    // Write your code here

    unordered_map<int,list<int>> adj;

    for(int i=0;i<e;i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> low(n+1,-1);
    vector<int> discovery(n+1,-1);
    vector<bool> visited(n+1);
    int parent = -1;
    int timer = 0;
    vector<vector<int>> result;

    for(int i = 0;i<n;i++){
        if(!visited[i])
            dfs(i,adj,low,discovery,timer,result,visited,parent);
    }
    
    return result;
}