 #include <iostream>
 #include <vector>
 using namespace std;

 void dfs(int node,vector<int> adj[], vector<bool> &visited){
        
        visited[node] = true;
            
            for(auto nbr : adj[node]){
                
                if(!visited[nbr])
                    dfs(nbr,adj,visited);
            }
    }
    
    bool isSingleComponent(int V, vector<int>adj[]){
        
        int components = 0;
	    
	    vector<bool> visited(V,false);
    //Get a component with non-zero degree
	    int i = 0;
	    for(i = 0;i<V;i++)
	        if(adj[i].size()>0)
	            break;
	//Perferm dfs on this component
	    dfs(i,adj,visited);
	//If there's still a node who's not visited and has more than one edges, then it's not a eularian path
	    for(int i = 0 ; i<V;i++){
	        if(!visited[i] && adj[i].size() > 0)
	            return false;
	    }
	
	    return true;
        
    }

	int isEularCircuit(int V, vector<int>adj[]){
	    // Code here
	   
	   if(isSingleComponent(V,adj)==false)
	     return 0;
	   
	   int oddCount = 0;
	   //Count odd degree nodes
	   for(int i = 0; i<V;i++){
	       if(adj[i].size()&1)
	            oddCount++;
	   }
	   //if odd degrees are more than 2 then there's no eularian path
	   if(oddCount>2)
	        return 0;
	   //if no odd count that means eularian circuit exists, so return 2 else return 1
	   return (oddCount) ? 1 : 2;
	   
	}