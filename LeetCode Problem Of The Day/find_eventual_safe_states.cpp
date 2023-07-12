#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, vector<vector<int>> &graph, vector<bool> &isSafe, vector<bool> &visited, vector<bool> &dfsVisited){

    visited[node] = true;
    dfsVisited[node] = true;
    isSafe[node] = false;

    for(auto nbr: graph[node]){
        if(dfsVisited[nbr]){
            return true;
        }else{
            if(!visited[nbr]){
                if(dfs(nbr,graph,isSafe,visited,dfsVisited))
                    return true;
            }
        }
    }
    dfsVisited[node] = false;
    isSafe[node] = true;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {


    int n = graph.size();
    vector<bool> isSafe(n,false);
    vector<bool> visited(n,false);
    vector<bool> dfsVisited(n,false);

    for(int i = 0; i < n; i++){
        if(!visited[i])
            dfs(i,graph,isSafe,visited,dfsVisited);
    }

    vector<int> ans;

    for(int i = 0; i<n;i++){
        if(isSafe[i])
            ans.push_back(i);
    }
    return ans;

}

int main(){

    //Graph 
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};

    for(auto i : eventualSafeNodes(graph))
        cout<<i<<" ";

    return 0;
}