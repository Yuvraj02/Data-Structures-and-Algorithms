#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <list>
#include <unordered_map>

using namespace std;

 int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int,list<pair<int,int>>> adj;

        int m = flights.size();
        for(int i = 0;i<m;i++){

            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }

        vector<int> cost(n,1e9);
         //{{stops,cost}, node}
        pair<pair<int,int>, int> f1 = {{0,0},src};
        cost[src] = 0;    
       
        priority_queue<pair<pair<int,int>,int>> q;
        q.push(f1);

        while(!q.empty()){

            pair<pair<int,int>, int> front = q.top();
            q.pop();

            int currCost = front.first.second;
            int stops = front.first.first;
            int node = front.second;

            if(stops>k)
                continue;

            for(auto nbr : adj[node]){

                int newCost = currCost + nbr.second;
                if(newCost < cost[nbr.first]){
                    
                    cost[nbr.first] = newCost;
                    q.push({{stops+1,newCost}, nbr.first});
                }
            }
        }

        for(auto i : cost)
            cout<<i<<" ";

        if(cost[dst]==1e9)
            return -1;
        else
            return cost[dst];
    }