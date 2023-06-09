#include <list>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adj;
  vector<int> inDegree(n,0);

  int m = edges.size();

  for(int i=0; i < m ;i++){

    int u = edges[i].first - 1;
    int v = edges[i].second - 1;

    adj[u].push_back(v);
    inDegree[v]++;
  }

  
  queue<int> q;

  for(int i = 0; i<n;i++){

    if(inDegree[i]==0)
      q.push(i);
  }

  int count = 0;
  while(!q.empty()){

    int front = q.front();
    q.pop();
    
    count++;

    for(auto neighbour : adj[front]){
      
      inDegree[neighbour]--;

      if(inDegree[neighbour]==0)
          q.push(neighbour);

    }

  }
  //cout<<"Count is : "<<count<<" and Nodes are : "<<n<<" ";
  if(count == n)
    return 0;

return 1;

 

}