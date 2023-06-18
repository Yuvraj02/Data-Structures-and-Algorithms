#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(int start, int V,vector<int>adj[],vector<int> &color){
        
	   queue<int> q;
	   
	   color[start] = 0;
	   q.push(start);
	   
	   while(!q.empty()){
	       
	       int front = q.front();
	       q.pop();
	       
	       for(auto nbr : adj[front]){
	           
	           if(color[nbr]==-1){
	               
	              color[nbr] = !color[front];
	              q.push(nbr);
	              
	           } else if(color[front]==color[nbr])
	                return false;
	           
	       }
	   
	   }
	   
	   return true; 
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	   vector<int> color(V,-1);
	   
	   //bool flag = 
	   for(int i = 0; i<V;i++){
	       if(color[i]==-1)
	            if(bfs(i,V,adj,color)==false)
	                return false;
	   } 
	   
	   return true;
	}