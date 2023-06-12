#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int findParent(vector<int> &parent, int node){

    if(node==parent[node])
        return node;

    //The below line takes time, so we have to do path compression
    //return findParent(parent,parent[node])

    //Do path compression to save time
    return parent[node] = findParent(parent,parent[node]);
}


void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){

    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }else if(rank[u] > rank[v]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}

bool comparator(vector<int> &edges1, vector<int> &edges2){

    return edges1[2] < edges2[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n){

    //Step 1: Implement disjoint set functions
    //We add these functions to check whether the 2 vertices belong to same component or not 
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i = 0; i<=n;i++){
        parent[i]=i;
    }

    //Step 2 : Sort the edges in terms of wait, as we select smallest weighted edge
    sort(edges.begin(),edges.end(),comparator);

    //Traverse through each edge and check if it's in the component or not
    //If not, then merge these two edges using union set function and add there weight

    int minWeight = 0;

    for(int i = 0; i<edges.size();i++){

        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);
        int weight = edges[i][2];

        //If parents are not same then merge
        if(u!=v){
            unionSet(u,v,parent,rank);
            minWeight += weight;
        }

    }
    
    return minWeight;

}


int main(){ 

    int n = 4,e = 4;

        vector<vector<int>> edges = {{0, 1, 3},
                                     {0, 3, 5},
                                     {1, 2, 1},
                                     {2, 3, 8}};

    cout<<minimumSpanningTree(edges,n);

    return 0;
}