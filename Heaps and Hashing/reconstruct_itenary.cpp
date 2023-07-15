#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <stack>

using namespace std;

/*
Dataset
"Chennai" -> "Banglore"
"Bombay"  -> "Delhi"
"Goa"     -> "Chennai"
"Delhi"   -> "Goa"

ReverseMap
"Banglore" -> "Chennai"
"Delhi"    -> "Chennai"
"Chennai"  -> "Goa"
"Goa"      -> "Delhi"

*/
  void dfs(int node, unordered_map<int,list<int>> &adj, vector<bool> &visited,stack<int> &s){

        visited[node] = true;

        for(auto nbr : adj[node]){
            if(visited[nbr]==false){
                dfs(nbr,adj,visited,s);
            }
        }
        s.push(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

            unordered_map<string,int> mapp;
            unordered_map<int,string> anotherMapp;
            int map_num = 0;
            
            //Map cities with numbers
            for(int i = 0; i<tickets.size();i++){
                    //If current ticket is not mapped yet, then map it
                    //Map both the tickets if possible
                    if(mapp.find(tickets[i][0])==mapp.end()){
                        mapp[tickets[i][0]] = map_num;
                        anotherMapp[map_num] = tickets[i][0];
                        map_num++;
                    }
                
                    if(mapp.find(tickets[i][1])==mapp.end()){
                        mapp[tickets[i][1]] = map_num;
                        anotherMapp[map_num] = tickets[i][1];
                        map_num++;
                    }
            }
         
            unordered_map<int,list<int>> adj;
            int n = map_num;
            for(int i = 0; i<tickets.size();i++){
                int u = mapp[tickets[i][0]];
                int v = mapp[tickets[i][1]];

                adj[u].push_back(v);
            } 
            vector<bool> visited(n,false);

            stack<int> s;
            //Now perform Topological Sort
            for(int i = 0; i<n;i++){
                if(!visited[i])
                    dfs(i,adj,visited,s);
            }   
            vector<string> ans;
            while(!s.empty()){
                ans.push_back(anotherMapp[s.top()]);
                s.pop();
            }
            
            return ans;
    }

int main(){

    vector<vector<string>> tickets = {{"Chennai","Bangalore"},
                                    {"Bombay","Delhi"},
                                    {"Goa", "Chennai"},
                                    {"Delhi","Goa"}};
    for(auto i : findItinerary(tickets))
        cout<<i<<" --> ";
    cout<<"xxx";
    return 0;
}