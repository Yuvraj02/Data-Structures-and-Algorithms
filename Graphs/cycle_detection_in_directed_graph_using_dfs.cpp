#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

bool dfs(int node, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited,
                  unordered_map<int,bool> &dfsVisited){
        
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto neighbour : adj[node]){

            if(visited[neighbour]==true && dfsVisited[neighbour]==true)
              return true;
            
            if(!visited[neighbour]){
              bool cycleDetected = dfs(neighbour, adj,visited,dfsVisited);
              if(cycleDetected)
                return true;
            }

        }
  //Back Track
    dfsVisited[node] = false;
  return false;

}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adj;

  int m = edges.size();

  for(int i=0;i<m;i++){

    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int,bool> dfsVisited;
  unordered_map<int,bool>  visited;

  for(int i = 0; i<n;i++){

      if(!visited[i]){
        bool cycleDetected = dfs(i,adj,visited,dfsVisited);
        if(cycleDetected)
          return true;
      }
  }
  return false;
}

int main(){

    int n = 5;

    vector<pair<int,int>> edges = { {1 ,2},
                                    {4 ,1},
                                    {2 ,4},
                                    {3 ,4},
                                    {5 ,2},
                                    {1 ,3}};


    if(detectCycleInDirectedGraph(n,edges))
        cout<<"Cycle Detected !";
    else
        cout<<"No Cycle Detected";

}