 #include <iostream>
 #include <vector>
 
 using namespace std;
 
  int findParent(int node, vector<int> &parent){

        if(parent[node]==node)
            return node;

        return parent[node] = findParent(parent[node], parent);
    }

    void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank){

         u = findParent(u,parent);
         v = findParent(v,parent);

        if(rank[u]<rank[v]){
            parent[u] = v;
        }else if(rank[v] < rank[u]){
            parent[v] = u;
        }else{
            parent[v] = u;
            rank[u]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> parent(n);
        vector<int> rank(n,0);

        //Initially Parent of a node are themselves
        for(int i = 0; i<n;i++){
            parent[i] = i;
        }

        int extraEdges = 0;
        for(int i = 0; i<connections.size();i++){

            int u = connections[i][0];
            int v = connections[i][1];

            if(findParent(u,parent) == findParent(v,parent))
                extraEdges++;
            else{
                unionByRank(u,v,parent,rank);
            }
        }

        int components = 0;
        for(int i = 0; i<n;i++){
            if(parent[i]==i)
                components++;
        }

        if(extraEdges >= components-1){
            return components-1;
        }else
            return -1;
    }