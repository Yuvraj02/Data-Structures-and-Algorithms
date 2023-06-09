#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

void reverse(vector<int> &ans){

	int i = 0,j=ans.size()-1;

	while(i<=j){

		swap(ans[i],ans[j]);
		i++;
		j--;
	}

}

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int,list<int>> adj;

	for(int i = 0;i<m;i++){

		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	unordered_map<int, bool> visited;
	unordered_map<int,int> parent;	

	vector<int> ans;
	queue<int> q;
	
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	while(!q.empty()){

		int front = q.front();
		q.pop();

		for(auto neighbour : adj[front]){

			if(!visited[neighbour]){
				q.push(neighbour);
				visited[neighbour] = true;
				parent[neighbour] = front;
			}
		}
	}
	
	ans.push_back(t);
	while(t!=s){
		ans.push_back(parent[t]);
		t = parent[t];
	}

		
	reverse(ans);
	return ans;
}

int main(){

    int v = 4, e = 4;
    vector<pair<int,int>> edges = {{1 ,2},
                                   {2 ,3},
                                   {3 ,4},
                                   {1 ,3}};

    int s = 1, t = 4;

    for(auto i : shortestPath(edges,v,e,s,t))
        cout<<i<<" ";
}