  #include <iostream>
  #include <vector>
  #include <unordered_map>
  #include <queue>

  using namespace std;

bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    int m = prerequisites.size();
	    vector<pair<int,int>> edges(m);
	    for(int i = 0;i<m;i++){
	        
	        edges[i].first = prerequisites[i].second;
	        edges[i].second = prerequisites[i].first;
	    }
	    
	    unordered_map<int,list<int>> adj;
	    vector<int> inDegree(n,0);
	    
	    for(int i = 0; i<m;i++){
	        int u = edges[i].first;
	        int v = edges[i].second;
	        
	        adj[u].push_back(v);
	        inDegree[v]++;
	    }
	    
	    vector<bool> visited(n,false);    
	    queue<int> q;

	    for(int i = 0 ;i<n;i++){
	           if(inDegree[i]==0)
	            q.push(i);
	    }
	    
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        
	        for(auto nbr : adj[front]){
	                
	                inDegree[nbr]--;
	                if(inDegree[nbr]==0)
	                    q.push(nbr);
	                
	        }
	        
	    }
	   
	   
	    for(auto i : inDegree)
	        if(i==1)
	            return false;
	   return true;
	}