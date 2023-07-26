#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
bool solve(int i, vector<int> &arr, int sum,vector<vector<int>> &dp){
        
        if(sum==0)
            return true;
        
        if(sum<0 || i>=arr.size())
            return false;
        
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        
        int include = true && solve(i+1,arr,sum-arr[i],dp);
        
        int exclude = solve(i+1,arr,sum,dp);
        
        return dp[i][sum] = include || exclude;
        
    }
    
    bool solveTab(vector<int>arr, int target){
        
        int n = arr.size();
        vector<vector<int>> dp(n+2,vector<int>(target+1,0));
        
        //Base case analysis
        for(int i = 0; i<=arr.size();i++){
            dp[i][0] = true;
        }
        
        //If sum is not 0 then everything else is false Important BASE CASE
        for(int i = 1; i<=target; i++){
            dp[n][i] = false;
        }
        
        
        for(int i = n-1; i>=0;i--){
            
            for(int sum = 0; sum<=target;sum++){
                
                int include = false;
                
                if(sum-arr[i] >= 0){
                    include = true && dp[i+1][sum-arr[i]];
                }
                
                int exclude = dp[i+1][sum];
                
                dp[i][sum] = (include || exclude);
            }
            
        }
        
        return dp[0][target];
    }
    
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
         int n = arr.size();
         vector<vector<int> > dp(n+1, vector<int> (sum+1, -1));
         
         //return solve(0,arr,sum,dp);
         return solveTab(arr,sum);
    }

    int main(){

        vector<int> arr = {3, 34, 4, 12, 5, 2};
        int sum = 9;
        cout<<boolalpha<<isSubsetSum(arr,sum)<<endl;
    
        return 0;
    }