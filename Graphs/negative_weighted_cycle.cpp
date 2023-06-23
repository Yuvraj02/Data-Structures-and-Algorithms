#include <iostream>
#include <vector>

using namespace std;

int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    if(edges.size()==0)
	        return 0;
	        
	    vector<int> dist(n+1,1e9);
	    dist[edges[0][0]] = 0;
	    
	    for(int i = 1; i<=n;i++){
	        
	        for(int j = 0; j<edges.size();j++){
	            
	            int u = edges[j][0];
	            int v = edges[j][1];
	            
	            int w = edges[j][2];
	            
	            //newDistance should be dist[u] + w and old one is dist[v]
	            if(dist[u]!=1e9 && (dist[u] + w < dist[v]))
	                dist[v] = dist[u] + w;
	        }
	        
	    }
	    
	    for(int i = 0;i<edges.size();i++){
	        int u = edges[i][0];
	        int v = edges[i][1];
	        int w = edges[i][2];
	        
	        if(dist[u] != 1e9 && (dist[u] + w < dist[v]))
	            return 1;
	    }
	    return 0;
	}