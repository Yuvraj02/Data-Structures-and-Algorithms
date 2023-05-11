#include <iostream>
#include <algorithm>

using namespace std;

//Recursive Solution doesn't give correct output
int solve(int i, int arr[], int n, int k){

    if(i==0)
        return 0;

    int ans;

    if(arr[i]-arr[i-1] < k){

        if(i>=2){

                int include = arr[i] + arr[i-1] + solve(i-2,arr,n,k);

                int exclude = solve(i-1,arr,n,k);

               ans = max(include,exclude);
        }else{

            int include = arr[i] + arr[i-1];
            int exclude = solve(i-1,arr,n,k);

            ans = max(include,exclude);
        }

    }
    return ans;
}

int solveTab(int arr[], int N, int K)
{
    // Sort input array in ascending order.
    sort(arr, arr+N);
 
    int dp[N];

    dp[0] = 0;
 
    for (int i = 1; i < N; i++)
    {
        int ans;

        if (arr[i] - arr[i-1] < K)
        {
            if (i >= 2){

                int include = arr[i] + arr[i-1] + dp[i-2];
                int exclude = dp[i-1];
    
                ans = max(include,exclude);
            }else{

              int include = arr[i] + arr[i-1];
              int exclude = dp[i-1];

             ans = max(include,exclude);
            }   
                
        }

        dp[i] = ans;
    }
 
    return dp[N - 1];
}


int main(){
    int arr[] = {3, 5, 10, 15, 17, 12, 9};
    int n = 7;
    int k = 4;
   // sort(arr,arr+n);
   cout<<solveTab(arr,n,k);
    //cout<<solve(n-1,arr,n,k);

    return 0;
}