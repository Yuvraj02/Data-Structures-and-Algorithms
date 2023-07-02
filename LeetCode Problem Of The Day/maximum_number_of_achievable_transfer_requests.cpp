#include <iostream>
#include <vector>

using namespace std;
  
  void solve(int i, int n, vector<vector<int>> &requests, vector<int> &buildingCount,int count, int &ans){

        if(i>=n){
            //Now check if there's building with incorrect count, i.e net count != 0
            for(auto j : buildingCount){
                if(j!=0)
                    return;
            }
            //If every buildingCount is 0 then get max count if exists
            ans = max(count, ans);
            return;
        }

       
        //Include request
        buildingCount[requests[i][0]]--;
        buildingCount[requests[i][1]]++;
        solve(i+1,n,requests,buildingCount,count+1,ans);
        //Backtrack
        buildingCount[requests[i][0]]++;
        buildingCount[requests[i][1]]--;

         //Exclude request
        solve(i+1,n,requests,buildingCount, count, ans);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> buildingCount(n, 0);
        int ans = INT32_MIN;
        solve(0,requests.size(),requests,buildingCount,0,ans);
        return ans;
    }

    int main(){

        //N is the number of buildings
        int n = 5;
        vector<vector<int>> requests = {{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};

        cout<<maximumRequests(n,requests);

        return 0;
    }