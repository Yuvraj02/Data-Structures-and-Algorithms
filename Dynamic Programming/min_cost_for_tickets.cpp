#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;


int main(){
    vector<int> days = {2,5};
    vector<int> cost = {1,4,25};
    int n = cost.size();
    
    int ans = 0;

    queue<pair<int,int>> month;
    queue<pair<int,int>> week;

    for (int current_day : days)
    {
        while (!month.empty() && current_day >= month.front().first + 30)
            month.pop();
        while(!week.empty() && current_day >= week.front().first + 7)
            week.pop();

        week.push(make_pair(current_day, ans+cost[1]));
        month.push(make_pair(current_day, ans+cost[2]));
      
    ans = min({ans+cost[0], month.front().second,week.front().second});
    }
    cout<<ans;

    return 0;
}

int solve(int index, int n, vector<int> &days, vector<int> &cost,vector<int> &dp){
    if(index>=n)
        return 0;

    if(dp[index]!=-1)
        return dp[index];

    //Solve for Option 1-> 1 Day pass
    int option1 = cost[0] + solve(index+1, n, days,cost,dp);

    //Solve for option 2 -> 7 Day Pass
    int i;
    for(i=index; i<n && days[i] < days[index]+7 ; i++);
    int option2 = cost[1] + solve(i,n,days,cost,dp);
    
    //Solve for option 3 -> 30 Day Pass
    for(i = index; i<n && days[i] < days[index]+30 ; i++);
    int option3 = cost[2] + solve(i,n,days,cost,dp);

    return dp[index] = min({option1,option2,option3});
}

//Tabulation

int minimumCoins(int n, vector<int> days, vector<int> cost)
{  
    vector<int> dp(days[n-1]+1, -1);

    dp[n] = 0;

    for(int index = n-1 ;index>=0;index--){
        int option1 = cost[0] + dp[index+1];

        int i;
        for(i = index; i<n && days[i] < days[index]+7;i++);
        int option2 = cost[1] + dp[i];

        for(i = index; i<n && days[i] < days[index]+30 ; i++);
        int option3 = cost[2] + dp[i];

        dp[index]=min({option1,option2,option3});
    }

    //return solve(0,n,days,cost,dp);

    return dp[0];
}