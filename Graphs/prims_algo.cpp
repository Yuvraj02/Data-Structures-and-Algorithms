#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <list>
using namespace std;


vector<pair<pair<int,int>, int>> prims(vector<pair<pair<int,int>,int>> &edges, int n){

    int m = edges.size();
    unordered_map<int,list<pair<int,int>>> adj;

    for(int i = 0; i<m;i++){
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int weight = edges[i].second;

        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }

    vector<int> key(n+1,INT32_MAX);
    vector<bool> isPresentinMST(n+1,false);
    vector<int> parent(n+1,-1);

    key[1] = 0;
    parent[1] = -1;

    for(int i = 1; i<=n;i++){

        int miniNode;
        int minVal = INT32_MAX;
        //Step 1 : Find Node with minimum weight
        for(int k = 1; k<=n;k++){

            if(!isPresentinMST[k] && key[k] < miniNode){
                miniNode = k;
                minVal = key[k];
            }
        }

        //Mark minium weighted node as present in mst
        isPresentinMST[miniNode] = true;

        //Check if this miniNode is parent and if yes, then mark it
        for(auto neighbour : adj[miniNode]){

            //Get node value and weight of neighbour
            int node = neighbour.first;
            int weight = neighbour.second;

            if(!isPresentinMST[node] && weight<key[node]){
                parent[node] = miniNode;
                key[node] = weight;
            }
        }
    }

    vector<pair<pair<int,int>, int>> result;

    for(int i = 2; i<=n;i++){
        result.push_back({{parent[i],i},key[i]});
    }

    return result;
} 

int main(){

    int n = 5;
    vector<pair<pair<int,int>, int>> edges = {{{1,2},2},
                                              {{1,5},6},
                                              {{2,3},3},
                                              {{2,4},5},
                                              {{2,5},8},
                                              {{3,4},7}};
    
    for(auto i : prims(edges,n)){
       std::cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
    }

    return 0;
}