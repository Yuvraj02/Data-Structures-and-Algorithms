#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<vector<int>> edges = {{1,2},
                                 {0 ,3},
                                 {2 ,3},
                                 {3 ,3},
                                 {0 ,1},
                                 {1 ,2},
                                 {2 ,0}};

int n = 4;
int m = edges.size();

vector<int> ans[n];

for(int i=0;i<n;i++){
    int u = edges[i][0];
    int v = edges[i][1];

    ans[u].push_back(v);
    ans[v].push_back(u);
}

vector<vector<int>> adj(n);

for(int i=0;i<n;i++){

    adj[i].push_back(i);
    for(int j = 0; j < ans[i].size(); j++){
        adj[i].push_back(ans[i][j]);
    }    
}

    for(int i = 0 ;i < n;i++){
        for(int j = 0; j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;

}