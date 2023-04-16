#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxSatisfaction(vector<int>& satisfaction) {

    int n = satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    
    vector<int> curr(n+1,0);
    vector<int> next(n+1,0);

    for(int i = n-1;i>=0;i--){
        for(int time=i;time>=0;time--){
            int include = (time+1) * satisfaction[i] + next[time+1];
            int exclude = next[time];

            curr[time] = max(include,exclude);    
        }
        next = curr;
    }
    return next[0];
}

int solveMem(vector<int> &satisfaction, int i,int time,vector<vector<int>> &dp){

    if(i>=satisfaction.size())
        return 0;

    if(dp[i][time]!=-1)
        return dp[i][time];

    //Include
    int include = (time+1) * satisfaction[i] + solveMem(satisfaction,i+1,time+1,dp);

    //Exclude
    int exclude = solveMem(satisfaction,i+1,time,dp);

    dp[i][time] = max(include,exclude);

    return dp[i][time];

}

int solveTab(vector<int>& satisfaction){

    int n = satisfaction.size();

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    sort(satisfaction.begin(),satisfaction.end());

    for(int i = n-1;i>=0;i--){
        for(int time =i;time>=0;time--){
        int include = (time+1) * satisfaction[i] + dp[i+1][time+1];

        int exclude = dp[i+1][time];

        dp[i][time] = max(include,exclude);

        }
    }
   
    return dp[0][0];

}



int main(){
    vector<int> satisfaction = {-1,-8,0,5,-9};
    cout<<maxSatisfaction(satisfaction)<<endl;

    return 0;
}