#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited,int &count){
    
    visited[node] = true;
    count++;
    for(auto nbr : adj[node]){
        if(!visited[nbr])
            dfs(nbr,adj,visited,count);
    }
    
 }

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    
    int m = astronaut.size();
    
    unordered_map<int,list<int> > adj;
    for(int i = 0 ;i <m ;i++){
        
        int u = astronaut[i][0];
        int v = astronaut[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

        vector<bool> visited(n,false);
        
        vector<int> eachComponent;
        for(int i = 0; i<n;i++){
            if(!visited[i]){
                int count = 0;
                dfs(i,adj,visited,count);
                eachComponent.push_back(count);
            }
        }
        
        int pairs = (n*(n-1))/2;
        for(int i = 0; i<eachComponent.size();i++){
            int val = (eachComponent[i]*(eachComponent[i]-1))/2;
            pairs-=val;
        }
    return pairs;
}