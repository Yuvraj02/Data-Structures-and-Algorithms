  #include <iostream>
  #include <vector>
  #include <unordered_map>
  #include <queue>

  using namespace std;
  
  vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            // code here
            
            unordered_map<int,list<int>> adj;
            
            vector<int> inDegree(n,0);
            
            for(int i = 0; i<m;i++){
                
                int u = edges[i][0]-1;
                int v = edges[i][1]-1;
                
                adj[u].push_back(v);
                inDegree[v]++;
            }
            
            
            queue<int> q;
            vector<int> job(n,0);
            
            for(int i = 0;i<n;i++){
                    if(inDegree[i]==0){
                        q.push(i);
                        job[i] = 1;
                    }
            }
            
            
            while(!q.empty()){
                
                int front = q.front();
                q.pop();
                
                for(auto nbr : adj[front]){
                    
                    inDegree[nbr]--;
                    
                    if(inDegree[nbr]==0){
                        q.push(nbr);
                        job[nbr] = job[front]+1;
                    }
                    
                }

            }
            
            return job;
        }