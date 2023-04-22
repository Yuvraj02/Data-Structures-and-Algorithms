#include <iostream>
#include <vector>

using namespace std;

int solveMem(int index, int endingIndex,vector<int> &slices, int n,vector<vector<int>>&dp){
    if(n == 0 || index > endingIndex)
        return 0;

    if(dp[index][n]!=-1)
        return dp[index][n];

    int include = slices[index] + solveMem(index+2, endingIndex,slices, n-1,dp);

    int exclude = solveMem(index+1, endingIndex,slices, n,dp);

    return dp[index][n] =  max(include,exclude);
}

int solveTab(vector<int>& slices){

   int k = slices.size();

   vector<vector<int>> dp1(k+2,vector<int>(k+2,0));
   vector<vector<int>> dp2(k+2,vector<int>(k+2,0));

    //Case 1
   for(int i = k-2; i>=0;i--){
    for(int n = 1; n<=k/3;n++){
        
        int include = slices[i] + dp1[i+2][n-1];
        int exclude = dp1[i+1][n];

        dp1[i][n] = max(include,exclude);
    }
   }

   int case1 = dp1[0][k/3];

    for(int i = k-1;i>=1; i--){
        for(int n = 1; n<=k/3;n++){
            
            int include = slices[i] + dp2[i+2][n-1];

            int exclude = dp2[i+1][n];

            dp2[i][n] = max(include,exclude);
        }
    }

    int case2 = dp2[1][k/3];

    return max(case1,case2);
}

int maxSizeSlices(vector<int>& slices) {
   
    /* Memoization : 
        int k = slices.size(); //We have total k sizes
        vector<vector<int>> dp1(k,vector<int>((k/3)+1,-1));
        vector<vector<int>> dp2(k,vector<int>((k/3)+1,-1));
        //Eat first slice and don't eat last slice
        int case1 = solveMem(0,k-2,slices,k/3,dp1);

        //Don't eat first, eat last
        int case2 = solveMem(1,k-1,slices,k/3,dp2);
    */

  // return solveTab(slices);

int k = slices.size();

   vector<int> curr1(k+2, 0);
   vector<int> prev1(k+2, 0);
   vector<int> next1(k+2, 0);

   vector<int> curr2(k+2, 0);
   vector<int> prev2(k+2, 0);
   vector<int> next2(k+2, 0);

    //Case 1
   for(int i = k-2; i>=0;i--){
    for(int n = 1; n<=k/3;n++){
        
        int include = slices[i] + next1[n-1];
        int exclude = curr1[n];

        prev1[n] = max(include,exclude);
    }
    next1 = curr1;
    curr1 = prev1;
   }

   int case1 = curr1[k/3];

    for(int i = k-1;i>=1; i--){
        for(int n = 1; n<=k/3;n++){
            
            int include = slices[i] + next2[n-1];

            int exclude = curr2[n];

            prev2[n] = max(include,exclude);
        }
        next2 = curr2;
        curr2 = prev2;
    }

    int case2 = curr2[k/3];

    return max(case1,case2);

}

int main(){
    
    vector<int> slices = {1,2,3,4,5,6};
   
    cout<<maxSizeSlices(slices);

    return 0;
}