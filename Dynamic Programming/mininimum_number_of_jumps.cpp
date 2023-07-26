 #include <iostream>
 #include <vector>

 using namespace std;
 


 int solve(int i, int arr[], int target_index,vector<vector<int>> &dp){
        
        if(i==0){
            
            if(i+arr[i] >= target_index)
                return 1;
            else
                return INT_MAX;
        }
        
        if(dp[i][target_index]!=-1)
            return dp[i][target_index];
        
        
        int include = INT_MAX;
        if(arr[i]!=0 && i + arr[i] >= target_index)
            include = 1 + solve(i-1, arr, i,dp);
       
       int exclude = solve(i-1, arr, target_index,dp);
       
       return dp[i][target_index] = min(include,exclude);
    }
  
    int solveTab(int arr[], int n){
            
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        
        //Base case anaylsis
        for(int target_index = 1; target_index<n; target_index++){
            
            if(arr[0] >= target_index)
                dp[0][target_index] = 1;
        }
        
        for(int i = 1; i<=n-2;i++){
            
            for(int target_index = i+1; target_index < n; target_index++){
                
                int include = INT_MAX;
                
                if(arr[i]!=0 && i + arr[i] >= target_index)
                    include = 1 + dp[i-1][i];
       
                int exclude = dp[i-1][target_index];
       
                dp[i][target_index] = min(include,exclude);
                
            }
        }        
        
        return dp[n-2][n-1];
    }
    
    int spaceOptim(int arr[], int n){
        
        vector<int> curr(n+1,INT_MAX);
        vector<int> prev(n+1,INT_MAX);
        
        //
         for(int target_index = 1; target_index<n; target_index++){
            
            if(arr[0] >= target_index){
                curr[target_index] = 1;
                prev[target_index] = 1;
            }
        }
        
        for(int i = 1; i<=n-2;i++){
            
            for(int target_index = i+1; target_index < n; target_index++){
                
                int include = INT_MAX;
                
                if(arr[i]!=0 && i + arr[i] >= target_index)
                    include = 1 + prev[i];
       
                int exclude = prev[target_index];
       
                curr[target_index] = min(include,exclude);
            }
            prev = curr;
        }        
        
        return prev[n-1];
    }
    
    int optimized(int arr[], int n){
                
        //If there's only one element present then we are alreay at end of array so return 0; 
        if(n<=1)
            return 0;
        
        //If first element is 0 then we can't reach other values
        if(arr[0]==0)
            return -1;
        //Initially steps can be taken is the value of 1st index 
        int steps = arr[0];
        //Max reach will be the value of 1 index as it's the max as of now
        int maxReach = arr[0];
        
        int jumps = 1;
        
        //Start from second index
        for(int i = 1; i<n;i++){
            
            //If reached end then return jumps
            if(i==n-1)
                return jumps;
                
            //if more index can be covered from current element then store it in maxReach
            maxReach = max(maxReach, i + arr[i]);
            
            //Decrement steps
            steps--;
            
            if(steps==0){
                
                jumps++;
                //If i crosses maxReach, then we won't be able to reach end
                if(i>=maxReach)
                    return -1;
                //Now the steps would be the value of maxReach - current element
                //Jitta cover krke aaye ho utna subtract kar do
                steps = maxReach - i;
            }
        }
            
    return -1;
    }
  
    int minJumps(int arr[], int n){
        // Your code here
        //vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
       // int ans = solve(n-2,arr,n-1,dp);
       //int ans = solveTab(arr,n);
       //int ans = spaceOptim(arr,n);
       int ans = optimized(arr,n);
        if(ans<0 || ans == INT_MAX)
            return -1;
        else
            return ans;
        
    }