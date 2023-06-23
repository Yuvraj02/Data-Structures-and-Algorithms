#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<vector<int>> &g){

    int v = g.size();

     for(int i =0; i<v;i++){
        for(int j = 0; j<v;j++){
           std::cout<<g[i][j]<<" ";
        }
        std::cout<<endl;
    }
}

int main(){

    vector<vector<int>> graph = {{0, 1, 1, 1, 0},
                                 {1, 0, 1, 0, 0},
                                 {1, 1, 0, 0, 0},
                                 {1, 0, 0, 0, 1},
                                 {0, 0, 0, 1, 0}};

    //Complement the given graph;
    vector<vector<int>> g = graph;
    
    int v = g.size();

    for(int i =0; i<v;i++){
        for(int j = 0; j<v;j++){
            if(i==j)
                continue;
            
            g[i][j] = !g[i][j];
        }
    }

    //print(g);
    //Check if the graph is bipartite
    vector<int> color(v,-1);
    vector<bool> visited(v,false);

    queue<int> q;
    color[0] = 0;

    bool isBipartite = true;

    while(!q.empty()){

        int front = q.front();
        q.pop();
        
        for(int i = 0; i<v;i++){
            //if edge exists and the vertex is not colored then color it
            if(g[front][i] && color[i]==-1)
                color[i] = !front;
            else if (g[front][i] && color[i]==color[front]){
                isBipartite = false;
                break;
            }
        }

    }

    if(isBipartite)
        std::cout<<"Yes";
    else
        std::cout<<"No";

    return 0;
}