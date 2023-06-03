#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n,m;
    cout<<"Enter Number of Nodes : ";
    cin>>n;
    cout<<"Enter number of edges : ";
    cin>> m;

    vector<vector<bool>> graph(n,vector<bool>(n,false));

    for(int i=0;i<m;i++){
        int u,v;
        cout<<"Enter The Nodes to connect : ";
        cin>>u>>v;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    for(int i = 0; i<graph.size();i++){
        for(int j = 0; j<graph.size();j++){

            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}