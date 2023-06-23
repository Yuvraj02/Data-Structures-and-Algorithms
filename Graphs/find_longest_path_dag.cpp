#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <utility>
#include <stack>

using namespace std;

void dfs(int node, unordered_map<int,list<pair<int,int>>> &adj, vector<bool> &visited,stack<int> &s){

    visited[node] = true;

    for(auto nbr : adj[node]){
        if(!visited[nbr.first])
            dfs(nbr.first,adj,visited,s);
    }

    s.push(node);
} 

vector<int> longestPath(vector<vector<int>> &edges, int n,int src){

    unordered_map<int,list<pair<int,int>>> adj;

    int m = edges.size();

    for(int i = 0; i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v,w});
    }

    vector<bool> visited(n,false);

    stack<int> s;

    for(int i = 0; i < n;i++){
        if(!visited[i])
            dfs(i,adj,visited,s);
    }

    vector<int> dist(n,INT32_MIN);

    dist[src] = 0;
    while(!s.empty()){

        int node = s.top();
        s.pop();

        if(dist[node] != INT32_MIN){

            for(auto nbr : adj[node]){

                int adjNode = nbr.first;
                int currDistance = nbr.second;

                int newDistance = dist[node] + currDistance;
                if(newDistance > dist[adjNode]){
    
                    dist[adjNode] = newDistance;
                }

            }

        }
    }

    return dist;

}

int main(){

    int n = 6;

    vector<vector<int>> edges = {{0, 1, 5},
                                 {0, 2, 3},
                                 {1, 3, 6},
                                 {1, 2, 2},
                                 {2, 4, 4},
                                 {2, 5, 2},
                                 {2, 3, 7},
                                 {3, 5, 1},
                                 {3, 4, -1},
                                 {4, 5, -2}};
    int src = 0;
    for(auto i : longestPath(edges,n,src))
        std::cout<<i<<" ";

    return 0;
}