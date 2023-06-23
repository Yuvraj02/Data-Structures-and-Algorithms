#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

bool dfsCycleDetect(int node, int parent, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited){

    visited[node] = true;

    for(auto neighbour : adj[node]){
        
        if(visited[neighbour] == true && neighbour != parent)
            return true;
        
        if(!visited[neighbour]){
            bool isCycle = dfsCycleDetect(neighbour,node,adj,visited);
            if(isCycle)
                return true;
        }

    }
    return false;
}

int main(){

    vector<vector<int>> edges =  {{4 ,0},
                                 {4 ,3},
                                 {1 ,4},
                                 {4 ,3},
                                 {3 ,1}};

    int V = 5;
    int m = edges.size();

    unordered_map<int,list<int>> adj;

    //Adjacency list creation
    for(int i=0; i < m;i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    unordered_map<int, bool> visited;
    bool ans = false;
    for(int i =0; i < V;i++){

        if(!visited[i]){
            ans = dfsCycleDetect(i,-1,adj,visited); 
            if(ans)
                break;
        }
    }

    if(ans)
        cout<<"Cycle Detected!"<<endl;
    else    
        cout<<"No Cycle Detected";
    return 0;
}