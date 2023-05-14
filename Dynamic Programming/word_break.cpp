#include <iostream>
#include <vector>

using namespace std;


    bool isPresent(string s,vector<string>& wordDict){

        for(int i=0;i<wordDict.size();i++)
            if(s==wordDict[i])
                return true;
        
        return false;
    }

    bool solve(string s,vector<string>& wordDict,vector<int> &dp){
        
        if(s.size()==0)
            return true;

        if(dp[s.size()] != -1)
            return dp[s.size()];


        for(int i = 1; i<=s.size();i++){
            
            if(isPresent(s.substr(0,i),wordDict) && solve(s.substr(i,s.size()-i), wordDict,dp))
                return dp[s.size()] = true;
        }

        return dp[s.size()] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        vector<int> dp(s.size()+2,-1);

        return solve(s,wordDict,dp);
    }

int main(){

    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    cout<<wordBreak(s,wordDict);
    return 0;
}