#include <iostream>
#include <vector>

using namespace std;

int solve(int index, int capacity, int wt[], int val[]){
        
        if(index==0){
            if(wt[index] <= capacity){
                return val[index];
            }else{
                return 0;
            }
        }
        
        //Take or not take
        //Include
        int include = INT32_MIN;
        if(wt[index] <= capacity){
            include = val[index] + solve(index, capacity-wt[index], wt,val);
        }
        
        //Exclude
        int exclude = solve(index-1, capacity,wt,val);
        
        return max(include,exclude);
        
}
    
int solveMem(int index, int capacity, int wt[], int val[],vector<vector<int>> &dp){
        
    if(index==0){
        return (capacity / wt[0]) * val[0];
    }
        
    if(dp[index][capacity] != -1)
        return dp[index][capacity];
        
    int include = INT32_MIN;
    
    if(wt[index] <= capacity){
        include = val[index] + solveMem(index, capacity-wt[index],wt, val,dp);
    }
        
    int exclude = solveMem(index-1,capacity,wt,val,dp);
        
    return dp[index][capacity] = max(include, exclude);    
}


int knapSack(int N, int W, int val[], int wt[])
{    
    //return unboundedKnapsack(W,wt,val,N-1);
    vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
    return solveMem(N-1,W,wt,val,dp);    
}

int main(){

   int N = 2, W = 3;
   int val[] = {1, 1};
   int wt[] = {2, 1};
    cout<<knapSack(N,W,val,wt);
    return 0;
}