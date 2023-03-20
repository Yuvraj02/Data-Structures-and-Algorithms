#include <iostream>
#include <vector>
using namespace std;

//Tabulation Method
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int> dp(x+1,INT32_MAX);
    dp[0] = 0;

    for(int i = 1; i<=x;i++){
        for(int j = 0; j<num.size();j++){
            if(i-num[j]>=0 && dp[i-num[j]]!=INT32_MAX)
                dp[i] = min(dp[i], 1+dp[i-num[j]]);
        }
    }

    if(dp[x]==INT32_MAX)
        return -1;
    else
        return dp[x];

}


int main(){
    vector<int> num = {1,2,3};
    int x = 7;
    cout<<minimumElements(num,x);
    return 0;
}

// //DP : Memoization
// int minimumElem(vector<int> &num, int x, vector<int> &dp)
// {    

//     if(x==0)
//         return 0;

//     if(x<0)
//         return INT32_MAX;

//     if(dp[x]!=-1)
//         return dp[x];

//     int mini = INT32_MAX;

//     for(int i=0;i<num.size();i++){

//         int ans = minimumElem(num,x-num[i], dp);

//         if(ans!=INT32_MAX){
//             //These are the min coins value
//             mini = min(mini, 1+ans);
//         }
//     }
//     dp[x] = mini;
//     return dp[x];

// }


//Bruteforce recursive solution

// int minimumElements(vector<int> &num, int x)
// {
//         if(x==0)
//             return 0;
        
//         if(x<0)
//             return INT32_MAX;
        
//         int mini = INT32_MAX;

//         for(int i=0;i<num.size();i++){
//             int ans = minimumElements(num, x-num[i]);

//                 if(ans!=INT32_MAX){
//                     mini = min(mini,1+ans);
//                 }
//         }
//     return mini;
// }

