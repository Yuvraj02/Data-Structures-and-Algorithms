#include <iostream>
#include <vector>

using namespace std;

void printAdjMat(vector<vector<int>> &adj){

	for(int i = 0;i<adj.size();i++){
		for(int j = 0; j<adj[i].size();j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}

}

void multiply(vector<vector<int>> &A,vector<vector<int>> &B, vector<vector<int>> &C){

	int v = A.size();
	//Matrix Multiplication	
	for(int i = 0;i < v;i++){
		
		for(int j =0; j<v;j++){
			
			for(int k = 0; k<v;k++){
				C[i][j] += A[i][k]*B[k][j]; 
			}
		}
	}

}

int trace(vector<vector<int>> A){

	int sum = 0;
	for(int i = 0; i<A.size();i++){
		sum+=A[i][i];
	}
	return sum;
}

int countForDirected(vector<vector<int>> &edges, int n){

	vector<vector<int>> adj(n,vector<int> (n,0));

	int m = edges.size();

	for(int i = 0;i<m;i++){

		int u = edges[i][0];
		int v = edges[i][1];

		adj[u][v] = 1;

	}
	
	vector<vector<int>> aux1(n,vector<int> (n,0));
	
	vector<vector<int>> aux2(n,vector<int> (n,0));

	multiply(adj,adj,aux1);

	multiply(adj,aux1,aux2);

	int num = trace(aux2)/3;

	return num;
}

int countForUnDirected(vector<vector<int>> &edges, int n){

	vector<vector<int>> adj(n,vector<int>(n,0));

	int m = edges.size();

	for(int i = 0; i<m;i++){
		int u = edges[i][0];		
		int v = edges[i][1];
		
		adj[u][v] = 1;
		adj[v][u] = 1;		
	}	

	vector<vector<int>> aux1(n,vector<int>(n,0));

	vector<vector<int>> aux2(n,vector<int>(n,0));

	multiply(adj,adj,aux1);

	multiply(adj,aux1,aux2);

	int triangles = trace(aux2)/6;
	
	// printAdjMat(adj);

return triangles;
}

vector<int> countTriangles(int v1, vector<vector<int>>& edgeListOfDirectedGraph, int v2,
			vector<vector<int>>& edgeListOfUnDirectedGraph) {
	// Write your code here.

	int triangle1 = countForUnDirected(edgeListOfUnDirectedGraph, v2);
	int triangle2 = countForDirected(edgeListOfDirectedGraph,v1);
	
	return {triangle2, triangle1};
}