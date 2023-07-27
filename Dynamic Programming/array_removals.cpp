#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 int solve(int i, int j, vector<int> &arr , int k,vector<vector<int>> &dp){
            
        if(i>j)
            return 0;
        
        if(arr[j] - arr[i] <= k)
            return 0;
            
        if(dp[i][j] !=-1)
            return dp[i][j];
        
        //1. Remove element from left side
        int remove_left = 1 + solve(i+1,j,arr,k,dp);

        //2. Remove element from right side
        int remove_right = 1 + solve(i,j-1,arr,k,dp);
        
        return dp[i][j] = min(remove_left,remove_right);
        
    }
    
    int optimized(vector<int> &arr, int k){
        
        int i = 0;
        
        int maxLength = 0;
        
        for(int j = 0; j<arr.size() && i<arr.size(); j++){
            
            if(arr[j]-arr[i] <=k){
                
                maxLength = max(maxLength, j-i+1);
            }else{
                i++;
            }
        }
        return arr.size()-maxLength;
    }
    
    int removals(vector<int>& arr, int k){
        //Code here
        
        sort(arr.begin(),arr.end());
        
        int n = arr.size();
        
        //vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        
       // return solve(0,arr.size()-1,arr,k,dp);
       return optimized(arr,k);
    }

int main(){

    vector<int> arr = {1,3,4,9,10,11,12,17,20};
    int k = 4;
    cout<<removals(arr,k);
    return 0;
}