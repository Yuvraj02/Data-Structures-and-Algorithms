#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>
#include <utility>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edges, int vertices, int e, int source){

unordered_map<int, list<pair<int, int> > > adj;

for(int i = 0 ;i < e; i++){

    int u = edges[i][0];
    int v = edges[i][1];
    int dist = edges[i][2];

    adj[u].push_back({v,dist});
    adj[v].push_back({u,dist});
}

    set<pair<int,int>> s;
    vector<int> dist(vertices,INT32_MAX);

    dist[source] = 0;
    s.insert({0,source});

    while (!s.empty())
    {
        pair<int,int> top = *(s.begin());
        int topNode = top.second;
        int currDist = top.first;
        s.erase(top);

        for(auto neighbour : adj[topNode]){

            int newDistance = currDist + neighbour.second;

            if(newDistance < dist[neighbour.first]){
                
                //Delete old record in set if it's there
                auto record = s.find({dist[neighbour.first], neighbour.first});

                if(record!=s.end()){
                    s.erase(record);
                }

                dist[neighbour.first] = newDistance;
                s.insert({newDistance,neighbour.first});
            }

        }

    }
    return dist;
}


int main(){

    int v = 5; 
    int e = 7;

    vector<vector<int>> edges ={{0 ,1 ,7},
                                 {0 ,2 ,1},
                                 {0 ,3 ,2},
                                 {1 ,2 ,3},
                                 {1 ,3 ,5},
                                 {1 ,4 ,1},
                                 {3 ,4 ,7}};

    for(auto i : dijkstra(edges,v,e,0))
        cout<<i<<" ";
    return 0;
}