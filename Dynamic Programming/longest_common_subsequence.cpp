#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(string text1, string text2);

int main(){
    string text1 = "abcde", text2 = "ace";  
    cout<<longestCommonSubsequence(text1,text2);
    return 0;
}

 int solve(int i, int j, string &s1,string &s2){

        if(i>=s1.size() || j>=s2.size())
            return 0;

        if(s1[i]==s2[j])
            return 1 + solve(i+1,j+1,s1,s2);
        else
            return max(solve(i+1,j,s1,s2), solve(i,j+1,s1,s2));
        
    }

    int solveMem(int i, int j, string &s1,string &s2,vector<vector<int>> &dp){

        if(i>=s1.size() || j>=s2.size())
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(s1[i]==s2[j])
            return dp[i][j] = 1 + solveMem(i+1,j+1,s1,s2,dp);
        else
            return dp[i][j] = max(solveMem(i+1,j,s1,s2,dp), solveMem(i,j+1,s1,s2,dp));
        
    }

    int solveTab(string s1,string s2){
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));

        for(int i = n1-1; i>=0 ;i--){
            for(int j = n2-1; j>=0;j--){
                if(s1[i]==s2[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    return dp[0][0];
    }

    int spaceOptimized(string s1,string s2){
        int n1 = s1.size();
        int n2 = s2.size();

        //  vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        vector<int> curr(n2+1,0);
        vector<int> next(n2+1,0);

        for(int i = n1-1; i>=0 ;i--){
            for(int j = n2-1; j>=0;j--){
                if(s1[i]==s2[j])
                    curr[j] = 1 + next[j+1];
                else
                    curr[j] = max(next[j],curr[j+1]);
            }
            next = curr;
        }
    return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size()+1;
        int n2 = text2.size()+1;

        vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));

       // return solveMem(0,0,text1,text2,dp);
        //return solve(0,0,text1,text2);
        //return solveTab(text1,text2);
        return spaceOptimized(text1,text2);
    }