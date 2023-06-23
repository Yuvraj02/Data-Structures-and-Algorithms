#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <utility>
using namespace std;


vector<int> dijkstra(vector<vector<int>> &edges, int vertices, int m, int source) {
    // Write your code here.

    unordered_map<int,list<pair<int,int>>> adj;

    for(int i = 0; i<edges.size();i++){

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        
    }

    //{Cost, node}
    pair<int,int> s1 = {0,source};
    
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    
    vector<int> dist(vertices,INT32_MAX);
    
    dist[source] = 0;
    q.push(s1);

    while(!q.empty()){

        pair<int,int> top = q.top();
        q.pop();
        int node = top.second;
        int currDistance = top.first;
        
        for(auto nbr : adj[node]){
            int adjNode = nbr.first;
            int newDistance = dist[node] + nbr.second;
            
            if(newDistance < dist[adjNode]){
                
                dist[adjNode] = newDistance;
                q.push({newDistance,adjNode});
            }
        }
    }

    return dist;
}


int main(){

    int v = 5; 
    int e = 7;

    vector<vector<int>> edges ={{0 ,1 ,7},
                                 {0 ,2 ,1},
                                 {0 ,3 ,2},
                                 {1 ,2 ,3},
                                 {1 ,3 ,5},
                                 {1 ,4 ,1},
                                 {3 ,4 ,7}};

    for(auto i : dijkstra(edges,v,e,0))
        cout<<i<<" ";
    return 0;
}