#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& arr, int n, vector<int>& dp){

    if(n<0)
        return 0;

    if(n==0)
        return arr[0];

        if(dp[n]!=-1)
            return dp[n];

    int include = arr[n] + solve(arr,n-2, dp);

    int exclude = solve(arr,n-1, dp);

    dp[n] = max(include,exclude);

    return dp[n];
}

int main(){
    
    vector<int> arr = {2,1,4,9};

    int n = arr.size()-1;
    
    int prev2 = 0;
    int prev1 = arr[0];
    for(int i = 1; i<=n;i++){

        int include = prev2 + arr[i];
        int exlude = prev1;
        int curr = max(include,exlude);
        prev2 = prev1;
        prev1 = curr;
    }

    cout<<prev1;
//    cout<<solve(arr,n,dp);

    return 0;

}

