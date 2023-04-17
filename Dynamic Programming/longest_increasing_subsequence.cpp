#include <iostream>
#include <vector>
using namespace std;

int mostOptim(int n, int a[]){

    if(n==0)
        return 0;

    vector<int> ans;
    ans.push_back(a[0]);

    for(int i=1;i<n;i++){

        if(a[i]>ans.back())
            ans.push_back(a[i]);
        else{
            //Get index of just larger element
            int index = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }
    return ans.size();
}

int longestSubsequence(int n, int a[])
{

    return mostOptim(n,a);
}

int main(){

    const int N=16;
    int A[N] =  {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    cout<<longestSubsequence(N,A);

    return 0;
}


int solveTab(int A[], int n){

     vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
    for(int curr = n-1; curr>=0;curr--){
        for(int prev = curr-1; prev>=-1; prev--){
            
            int include = 0;
            if(prev==-1 || A[curr] > A[prev])
                include = 1 + dp[curr+1][curr+1];
            
            int exclude = dp[curr+1][prev+1];
            
            dp[curr][prev+1] = max(include,exclude);
        }
    }
           
       return dp[0][0];
}


int solveMem(int A[], int n,int curr, int prev,vector<vector<int>> &dp){
    // int size = output.size();
    
    if(curr>=n)
        return 0;

    if(dp[curr][prev+1] != -1)
        return dp[curr][prev+1];
    //Include Case
    int include = 0;
    if(prev==-1 || A[curr] > A[prev])
        include = 1 + solveMem(A,n,curr+1,curr,dp);

    //Exclude
        int exclude = solveMem(A,n,curr+1,prev,dp);
    
    dp[curr][prev+1] = max(include,exclude);
    return dp[curr][prev+1];
}


int spaceOptim(int n, int a[]){

vector<int> next(n+1,0);    
    vector<int> current(n+1,0);

    for(int curr = n-1;curr>=0;curr--){
        for(int prev = curr-1; prev>=-1;prev--){

            int include = 0;
            if(prev==-1 || a[curr] > a[prev])
                include = 1 + next[curr+1];

            int exclude = next[prev+1];
            current[prev+1] = max(include,exclude);
        }
        next = current;
    }

    return next[0];

}