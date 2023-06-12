#include <iostream>
#include <vector>

using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.

    vector<int> dist(n+1,1e9);

    dist[src] = 0;

    for(int i = 1; i<=n; i++){

        for(int j=0;j<m;j++){

            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e9 && (dist[u] + wt < dist[v])){
                dist[v] = dist[u] + wt;
            }
        }

    }

    bool negativeCycle = 0;

    for(int i = 0; i<m;i++){
        
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            if(dist[u]!=1e9 && (dist[u] + wt < dist[v])){
                negativeCycle = 1;
            }
    }

    if(negativeCycle)
        return -1;
    else
        return dist[dest];

}