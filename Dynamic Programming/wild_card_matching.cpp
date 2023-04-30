#include <iostream>
#include <vector>

using namespace std;

 bool solve(int i, int j, string s, string pattern,vector<vector<int>> &dp){
       
       //Base cases
        if(i==0 && j < 0)    //If both string and pattern traversal is complete return true 
            return true;

        if(i>0 && j==0)
            return false;

        if(i==0 && j>=0){ //If pattern is still left for traversal, then
            for(int k = 1; k<=j;k++){
                if(pattern[k]!='*')
                    return false;
            }
        return true;
        }

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(s[i]==pattern[j] || pattern[j] == '?'){
            return dp[i][j] = solve(i-1,j-1,s,pattern,dp);
        }else if (pattern[j]=='*'){
            return dp[i][j] = solve(i-1,j,s,pattern,dp) || solve(i,j-1,s,pattern,dp);
        }else{
            return false;
        }

    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(s.size()-1, p.size()-1, s,p,dp);
    }


int main(){
    string s = "abcde";
    string p = "a*c?e";
    cout<<isMatch(s,p);
    
    return 0;
}