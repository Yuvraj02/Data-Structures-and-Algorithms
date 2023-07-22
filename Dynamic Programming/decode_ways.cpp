#include <iostream>
#include <vector>

using namespace std;
 
 int solve(int i, string s,vector<int> &dp){
        if(i<s.size() && s[i]=='0')
            return 0;
        
        if(i>=s.size()-1){
            //ways++;
            return 1;
        }

        if(dp[i]!=-1)
            return dp[i];

        int ways = 0;
        //Include next number if it's in the range 1-26
            string num = "";
            num+=s[i];
            num+=s[i+1];

            if(stoi(num) <=26)
                ways += solve(i+2,s,dp);

        //Exclude next letter
            ways += solve(i+1,s,dp);
            return dp[i] = ways;
    }

    int numDecodings(string s) {
        int n = s.size();
        int ways = 0;
        vector<int> dp(n+1, -1);
        return solve(0,s,dp);
        //return solveTab(s);
    }