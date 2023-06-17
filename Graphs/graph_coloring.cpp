#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int node, vector<vector<int>> &graph, int n,vector<int> &color, int &c){

    for(int nbr =0;nbr<n;nbr++)
        if(graph[node][nbr] && color[nbr]==c)
            return false;
    return true;
}

bool colorGraph(int i, vector<vector<int>> &graph, int n, int m,vector<int> &color){

    if(i==n)
        return true;
    
    for(int c = 1; c<=m;c++){

        if(isSafe(i,graph,n,color,c)){

            color[i] = c;
            bool furtherSolution(colorGraph(i+1,graph,n,m,color));
            if(furtherSolution)
                return true;
            else
                color[i] = 0;

        }

    }

//Means nodes are still left but no color available so return false
    return false;
}

string graphColoring(vector<vector<int>> &graph, int m) {
    // Write your code here

    int n = graph.size();

    vector<int> color(n,0);

    if(colorGraph(0,graph,n,m,color))
        return "YES";
    else
        return "NO";
}