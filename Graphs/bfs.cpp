#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

void bfs(vector<int> &ans, unordered_map<int,list<int>> &adj, unordered_map<int, bool> &visited,int node){

    queue<int> q;

    q.push(node);
    visited[node] = true;

    while(!q.empty()){

        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto i : adj[front]){

            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){

    vector<pair<int,int>> edges = {{0 ,1},
                                   {0 ,3},
                                   {1 ,2},
                                   {2 ,3}};

    int vertex = 4; //0 1 2 3

    unordered_map<int, list<int>> adj;
    int m = edges.size();
    
    for(int i=0;i<m;i++){

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    unordered_map<int,bool> visited;

    for(int i=0;i<vertex;i++){

        if(!visited[i])
            bfs(ans,adj,visited,i);
    }

    for(auto i : ans)
        cout<<i<<" ";

    return 0;
}