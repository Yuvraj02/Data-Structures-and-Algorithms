#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>

using namespace std;

void dfs(int node, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited,stack<int> &s){

	visited[node] = true;

	for(auto nbr : adj[node]){

		if(!visited[nbr]){
			dfs(nbr,adj,visited,s);
		}

	}
	s.push(node);
}

void revDfs(int node, unordered_map<int,list<int>> transpose,unordered_map<int,bool> &visited){

	visited[node] = true;

	for(auto nbr : transpose[node]){
		
		if(!visited[nbr]){
			revDfs(nbr, transpose, visited);
		}

	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>> adj;

	for(int i = 0; i<edges.size();i++){

		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		
	}

	stack<int> s;
	unordered_map<int,bool> visited;

	//Topological
	for(int i = 0; i<v;i++){
			if(!visited[i])
				dfs(i, adj, visited, s);
	}

	//Transpose graph
	unordered_map<int,list<int>> transpose;

	for(int i = 0; i<v;i++){
		visited[i] = false;
 		for(auto nbr : adj[i]){

			transpose[nbr].push_back(i);
		}
	}

	//Dfs call using above ordering
	int count = 0;
	while(!s.empty()){
		int top = s.top();
		s.pop();
		if(!visited[top]){
			count++;
			revDfs(top,transpose,visited);
		}
	}
return count;
}