#include <iostream>
#include <vector>

using namespace std;
long long solve(vector<int>& arr, int n){

   long long prev2 = 0;
    long long prev1 = arr[0];
    for(int i = 1; i<=n;i++){

        long long include = prev2 + arr[i];
        long long exlude = prev1;
        long long curr = max(include,exlude);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

long long int houseRobber(vector<int>& val)
{
    // Write your code here.
    int n = val.size();
    if(n==1)
        return val[0];
    vector<int> first,second;

    for(int i=0;i<n-1;i++)
        first.push_back(val[i]);
     
    for(int i=1;i<n;i++)
        second.push_back(val[i]);
    
    int n1 = first.size()-1;
    int n2 = second.size()-1;

    return max(solve(first, n1),solve(second,n2));
}

int main(){
    
    vector<int> arr = {2,1,4,9};

    cout<<houseRobber(arr);
//    cout<<solve(arr,n,dp);

    return 0;

}

