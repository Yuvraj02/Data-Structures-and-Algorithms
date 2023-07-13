#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool canFinish(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        vector<int> inDegree(n, 0);
        //Creating Adjacency list
        for(int i = 0; i<edges.size();i++){

            int u  = edges[i][1];
            int v =  edges[i][0];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        //Using Topological Sort 
  
        vector<bool> visited(n,false);
        queue<int> q;
        for(int i = 0; i<n;i++){
            if(inDegree[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            
            int front = q.front();
            q.pop();

            for(auto nbr : adj[front]){
                inDegree[nbr]--;

                if(inDegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }

        for(int i = 0; i<n;i++){
            if(inDegree[i] >= 1)
                return false;
        }
        return true;
    }

    int main(){

        vector<vector<int>> prerequisites = {{1,0},{0,1}};
        int numCourses = 2; 

        cout<<canFinish(numCourses,prerequisites);

    return 0;
    }