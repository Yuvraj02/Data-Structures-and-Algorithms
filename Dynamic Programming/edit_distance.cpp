#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int i, int j, string &a, string &b,vector<vector<int>> &dp){
        
        if(i>=a.size()){

            return b.size()-j;
        }

        if(j>=b.size()){
            return a.size()-i;
        }            
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(a[i]==b[j])
            return solve(i+1,j+1,a,b,dp);
        
        //1. Insert    
        int insert = 1 + solve(i,j+1,a,b,dp);
        
        //2. Delete
        int del = 1 + solve(i+1,j,a,b,dp);
        
        //3. Replace
        int replace = 1 + solve(i+1,j+1,a,b,dp);
        
        return dp[i][j] = min({insert,del,replace});
        
    }

    int solveTab(string a, string b){
        int n1 = a.size();
        int n2 = b.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        //Base case for string a
        for(int j = 0; j<=b.size();j++){
            dp[n1][j] = b.size()-j;
        }
        //Base case for string b
        for(int i = 0;i<=a.size();i++){
            dp[i][n2] = a.size()-i;
        }

        for(int i = n1-1; i>=0 ;i--){

            for(int j = n2-1; j>=0;j--){

                if(a[i]==b[j])  
                    dp[i][j] = dp[i+1][j+1];
                else{
                //1.Insert
                int insert = 1 + dp[i][j+1];
                //2.Delete
                int del = 1 + dp[i+1][j];
                //3. Replace
                int replace = 1 + dp[i+1][j+1];
                
                dp[i][j] = min({insert,del,replace});
                }
            }
        }
    return dp[0][0];
    }

    int minDistance(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        //return solve(0,0,s,t,dp);
        return solveTab(s,t);
       
    }

int main(){
    string word1 = "horse", word2 = "ros";
    cout<<minDistance(word1,word2)<<endl;
    
    return 0;
}