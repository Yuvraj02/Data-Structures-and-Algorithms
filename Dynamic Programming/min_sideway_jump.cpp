#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
   
    vector<int> obstacles = {0,1,2,3,0};
    int n = obstacles.size()-1;
    vector<int> curr(4,INT32_MAX);
    vector<int> next(4,INT32_MAX);

    next[0]=0;
    next[1]=0;
    next[2]=0;
    next[3]=0;

    for(int currPos = n-1; currPos>=0;currPos--){
        for(int currLane = 1;currLane<=3;currLane++){

            if(currLane!=obstacles[currPos+1]){
                curr[currLane] = next[currLane];
            }else{
                int ans = 1e9;
                for(int i=1;i<=3;i++){
                    if(i!=currLane && i!=obstacles[currPos])
                        ans = min(ans, 1 + next[i]);
                }

                curr[currLane] = ans;
                next = curr;
            }

        }

    }
    cout<<min({next[2],1+next[1],1+next[3]});

    return 0;
}

int solve(vector<int>& obstacles, int currPos, int currLane,vector<vector<int>> &dp){
    
    if(currPos==obstacles.size()-1)
        return 0;

    if(dp[currLane][currPos]!=-1)
        return dp[currLane][currPos];

    if(obstacles[currPos+1] != currLane){
        return solve(obstacles,currPos+1,currLane,dp);
    }else{

        int ans = INT32_MAX;
        for(int i=1;i<=3;i++){
            if(currLane!=i && obstacles[currPos]!=i)
                ans = min(ans, 1 + solve(obstacles,currPos,i,dp));
        }

        dp[currLane][currPos] = ans;
        return dp[currLane][currPos];
    }

}

int tab(vector<int> obstacles){
     
    int n = obstacles.size()-1;
    vector<vector<int>> dp(4, vector<int>(n+1, 1e9));
    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for(int pos=n-1;pos>=0;pos--){
        for(int currLane = 1; currLane<=3;currLane++){
            
            if(obstacles[pos+1]!=currLane){
                dp[currLane][pos] = dp[currLane][pos+1];
            }else{
                int ans = 1e9;
                for(int i=1; i<=3;i++){
                    if(i!=currLane && i!=obstacles[pos])
                    //Do dp[i][pos+1] because pos contains INT32_MAX, so get value from next column
                        ans = min(ans, 1 + dp[i][pos+1]);
                }

                dp[currLane][pos] = ans;
            }

        }   
    }

    return min({1+dp[1][0], dp[2][0], 1+dp[3][0]});
}

//Recursion : ----------------
// int solve(vector<int>& obstacles, int currPos, int currLane) {
//         int n = obstacles.size();
//         if(currPos == n-1){
//             return 0;
//         }

//         // If there is no obstacle at current lane then move straight
//         if(obstacles[currPos+1]!=currLane){
//             return solve(obstacles,currPos+1,currLane);
//         }else{
//             int ans = INT32_MAX;
//             //Try other lane
//             for(int i=1;i<=3;i++){
//                 //check if frog can't jump on same lane and the other lane doesn't contain any obstacle at current poosition
//                 if(i!=currLane && i!=obstacles[currPos])
//                     ans = min(ans, 1 + solve(obstacles,currPos,i));
//             }
//         return ans;
//         }
// }