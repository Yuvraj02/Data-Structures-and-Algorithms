#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <list>
#include <unordered_map>

using namespace std;
  
  vector<int> topoSort(vector<int> adj[], int K){
        
        vector<int> inDegree(K,0);
        for(int i = 0; i<K;i++){
            
            for(auto nbr : adj[i])
                inDegree[nbr]++;
        }
        
        queue<int> q;
       vector<int> ans;
       for(int i = 0; i<K;i++){
           
           if(inDegree[i]==0)
                q.push(i);
       }
       
       while(!q.empty()){
           
           int front = q.front();
           q.pop();
            
           ans.push_back(front);
            
           for(auto nbr : adj[front]){
               
               inDegree[nbr]--;
               
               if(inDegree[nbr]==0)
                q.push(nbr);
           }
       }
       
       return ans;
        
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        
        vector<int> adj[K];
        vector<int> inDegree(K,0);
        for(int i = 0; i<N-1;i++){
            
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.size(),s2.size());
            for(int j = 0; j<len;j++){
                
                if(s1[j]!=s2[j]){
                    
                    adj[s1[j] - 'a'].push_back(s2[j] -'a');
                    inDegree[s2[j] - 'a']++;
                    break;
                }
                
            }
            
        }
       
        vector<int> topo = topoSort(adj,K);
        
        string order = "";
        
        for(auto i : topo)
                order += i + 'a';
    return order;
    }