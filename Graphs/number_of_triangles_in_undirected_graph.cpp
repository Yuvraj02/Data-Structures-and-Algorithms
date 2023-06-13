#include <iostream>
#include <vector>

using namespace std;

void multiply(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C){

    int v = A.size();

    for(int i = 0; i<v;i++){
        for(int j=0;j<v;j++){
            for(int k = 0; k<v;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int trace(vector<vector<int>> &A){

    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
      sum += A[i][i];
    }
    return sum;
}

int triangleInGraph(vector<vector<int>> &graph, int v) {
    // Write your code here

    int n = graph.size();

    vector<vector<int>> aux1(n,vector<int>(n,0));
    vector<vector<int>> aux2(n,vector<int>(n,0));
    
    multiply(graph, graph, aux1);

    multiply(graph, aux1, aux2);


    return trace(aux2)/6;

}