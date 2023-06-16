#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

void dfs(int node,vector<int> &inTime, vector<int> &outTime, int &timer,unordered_map<int,list<int>> &adj, vector<bool>&visited){

	inTime[node] = ++timer;	
	visited[node] = true;

	for(auto nbr : adj[node]){

		if(!visited[nbr])
			dfs(nbr,inTime,outTime,timer,adj,visited);
		
	}
	
	outTime[node] = ++timer;
}

bool check(int x, int y,vector<int> &inTime, vector<int> &outTime){

	if(inTime[x] < inTime[y] && outTime[x] > outTime[y])
		return true;
	
	return false;
}

void findOliver(vector<vector<int>> &edges, int n){

	unordered_map<int,list<int>> adj;

	int m = edges.size();
	for(int i = 0; i<m;i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int q;
	cin>>q;
	while(q--){
		int move,x,y;
		cin>>move>>x>>y;

		vector<bool> visited(n,false);
		vector<int> inTime(n,0),outTime(n,0);
		int timer = 0;

		dfs(1,inTime,outTime,timer,adj,visited);

		bool found = false;

		if(!check(x,y,inTime,outTime) && !check(y,x,inTime,outTime)){
			found = false;
		}else if(move==0){
			//Then y should be subtree of x
			if(inTime[x] < inTime[y] && outTime[x]>outTime[y])
				found = true;

		}else if(move==1){
			//Then x should be subtree of y
			if(inTime[y] < inTime[x] && outTime[y] > outTime[x])
				found = true;
		}

		if(found)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

}

int main() {
	
	int n;
	cin>>n;

	vector<vector<int>> edges(n,vector<int>(2,0));

	for(int i=1;i<=n-1;i++){
		cin>>edges[i][0]>>edges[i][1];
	}

	findOliver(edges,n);

	return 0;

}