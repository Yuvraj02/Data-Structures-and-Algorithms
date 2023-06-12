#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;


void dfs(int node, int parent, unordered_map<int,list<int>> &adj, vector<int> &disc,vector<int> &low, 
         vector<bool> &visited,int &timer,vector<int> &ans)
{

    visited[node] = true;

    disc[node] = low[node] = timer++;

    int child = 0;

    for(auto nbr : adj[node]){

        if(nbr==parent)
            continue;
        
        if(!visited[nbr]){
            dfs(nbr,node,adj,disc,low,visited,timer,ans);
            //Update the low of current if it's less
            low[node] = min(low[nbr],low[node]);

            if(low[nbr] >= disc[node] && parent!=-1){
                ans.push_back(node);
            }
         child++;
        }else{
         
         low[node] = min(low[node],disc[nbr]);

        }

    }

    if(parent==-1 && child > 1){
        ans.push_back(node);
    }

}

vector<int> articulationPoint(vector<vector<int>> &edges, int n){

    unordered_map<int, list<int>> adj;

    for(int i = 0; i<n;i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> disc(n+1,-1);
    vector<int> low(n+1,-1);
    vector<bool> visited(n+1,false);
    int parent = -1;
    int timer = 0;

    vector<int> ans;

    for(int i =0;i<n;i++){

        if(!visited[i])
            dfs(i,parent,adj,disc,low,visited,timer,ans);

    }

    return ans;
}

int main(){

    int n = 5;

    vector<vector<int>> edges = {{0,1},
                                 {1,4},
                                 {4,3},
                                 {4,2},
                                 {3,2}};

    for(auto i : articulationPoint(edges,n)){
        cout<<i<<" ";
    }

    return 0;
}