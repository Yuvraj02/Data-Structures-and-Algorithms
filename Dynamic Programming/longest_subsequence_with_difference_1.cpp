 #include <iostream>
 #include <vector>
 using namespace std;
 
 int solve(int i,int prev ,int N, int A[],vector<vector<int>> &dp){
        
        if(i>=N)
            return 0;
            
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
            
        int include = 0;
        if(prev==-1 || abs(A[i] - A[prev]) == 1){
            include = 1 + solve(i+1,i,N,A,dp);
        }
        
        int exclude = solve(i+1,prev,N,A,dp);
        
        return dp[i][prev+1] =  max(include,exclude);
        
    }

    int longestSubsequence(int N, int A[])
    {
        // code here
        int prev = -1;
        vector<vector<int>> dp(N+1,vector<int>(N+1, -1));
        int ans = solve(0, prev,N, A,dp);

        return ans;
    }


    int main(){

        int A[] = {1,2,3,4,5};
        int N = 5;
        cout<<longestSubsequence(N,A);

        return 0;
    }