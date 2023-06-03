#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph {
    public:
        unordered_map<int,list<int>> adj;

        void addEdge(int u, int v, bool isDirected){

            adj[u].push_back(v);

            if(!isDirected)
                adj[v].push_back(u);
        }

        void printAdjList(){

            for(auto i : adj){
                std::cout<<i.first<<"-->";
                    for(auto j : i.second)
                        std::cout<<j<<", ";
                std::cout<<endl;
            }
        }
};

int main(){

    graph g;
    g.addEdge(0,1,true);
    g.addEdge(1,2,true);
    g.addEdge(2,3,true);
    g.addEdge(3,0,true);
    g.addEdge(2,0,true);
    g.printAdjList();

    return 0;
}