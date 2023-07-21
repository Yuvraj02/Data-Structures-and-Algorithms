#include <iostream>
#include <vector>
#include <utility>

using namespace std;

    pair<int,int> solve(vector<int> &arr, int curr, int prev,vector<vector<pair<int,int>>> &dp){
        if(curr>=arr.size())
            return {0,1};
        
        if(dp[curr][prev+1].first!=-1)
            return dp[curr][prev+1];

         // {Length of Subsequence, Frequency Of Subsequence}
         pair<int,int> include = {0,0};
        
         if(prev==-1 || arr[curr] > arr[prev]){
             include = solve(arr,curr+1, curr,dp);
             include.first++;
         }

         pair<int,int> exclude = solve(arr,curr+1, prev,dp);

        if(include.first == exclude.first){
            dp[curr][prev+1] = {include.first, include.second + exclude.second};
        }else if(include.first > exclude.first){
            dp[curr][prev+1] = include;
        }else{
            dp[curr][prev+1] =  exclude;
        }
        return dp[curr][prev+1];
    }

    int findNumberOfLIS(vector<int>& nums) {
        int prev = -1;
        int n = nums.size();
        vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(n+1,{-1,-1}));
        
        return solve(nums,0,prev,dp).second;
    }

    int main(){

        vector<int> nums = {1,3,5,4,7};
        cout<<findNumberOfLIS(nums)<<endl;
        return 0;
    }
