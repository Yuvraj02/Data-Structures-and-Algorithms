#include <iostream>
#include <vector>

using namespace std;


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

int main(){
    vector<int> obstacles = {0,1,2,3,0};
    int n = obstacles.size();
    vector<vector<int>> dp(4, vector<int>(n, -1));
    

    cout<<solve(obstacles,0,2,dp);

    return 0;
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