#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <stack>
#include <list>

using namespace std;

void dfs(int node, unordered_map<int,list<pair<int,int> > > &adj, unordered_map<int,bool> &visited,
             stack<int> &s){
                 
                visited[node] = true;
                
                for(auto neighbour : adj[node]){
                        
                        if(!visited[neighbour.first])
                            dfs(neighbour.first, adj,visited,s);
                }
                
        s.push(node);
        
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        unordered_map<int,list<pair<int,int>>> adj;
        
        //Adj list for weighted graph
        for(int i = 0; i<M; i++){
                
            int u = edges[i][0];
            int v = edges[i][1];
            
            int dist = edges[i][2];
            
            adj[u].push_back({v,dist});
        }
        
        unordered_map<int,bool> visited;
       
        stack<int> s;
        
        for(int i = 0; i<N; i++){
                
            if(!visited[i])
                dfs(i,adj,visited,s);
            
        }
        
        vector<int> dist(N,INT32_MAX);
        
        int src = 0;
        
        dist[src] = 0;
        while(!s.empty()){
            
            int top = s.top();
            s.pop();
            
            if(dist[top]!=INT32_MAX){
                
                for(auto i : adj[top]){
                    
                    int newDistance = dist[top] + i.second;
                    
                    if(newDistance < dist[i.first]){
                        dist[i.first] = newDistance;
                    }
                }
            }
            
        }
        
        for(int i = 0; i<dist.size();i++)
            if(dist[i]==INT32_MAX)
                dist[i]=-1;
        
        return dist;
    }