#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;


bool cycleDetect(int node, unordered_map<int,list<int> > &adj, unordered_map<int,bool> &visited,
                    unordered_map<int,int> &parent){
    
    queue<int> q;
    visited[node] = true;
    parent[node] = -1;
    q.push(node);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        //Traverse Neighbours
        for(auto neighbours : adj[front]){

            if(visited[neighbours]==true && neighbours!=parent[front])
                return true;
            
            if(!visited[neighbours]){
                    visited[neighbours] = true;
                    parent[neighbours] = front;
                    q.push(neighbours);
            }

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

    unordered_map<int,list<int>> adj;
    int m = edges.size();
    int n = 5;

    for(int i = 0; i<m;i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;

    unordered_map<int,int> parent;

    bool ans = false;
    for(int i =0; i < n;i++){

        if(!visited[i]){
            ans = cycleDetect(i,adj,visited,parent);
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