#include <iostream>
#include <vector>

using namespace std;

 int solve(string a, string b, int i, int j,vector<vector<int>>&dp){
        if(i==a.size()){
            return b.size()-j;
        }

        if(j==b.size())
            return a.size()-i;

        if(dp[i][j]!=-1)
            return dp[i][j];

        int ans = 0;
        if(a[i]==b[j])
            return solve(a,b,i+1,j+1,dp);
        else {

            int insert = 1 + solve(a,b,i,j+1,dp);

            int del = 1 + solve(a,b,i+1,j,dp);

            int replace = 1 + solve(a,b,i+1,j+1,dp);

            ans = min({insert,del,replace});
        }

        return dp[i][j] = ans;

       // return dp[i][j];
    }

    int solveMem(int i, int j, string a, string b,vector<vector<int>>& dp){
        if(i==a.size())
            return b.size()-j;

        if(j==b.size())
            return a.size()-i;

        if(dp[i][j]!=-1)
            return dp[i][j];

        int ans = 0;
        if(a[i]==b[j])
            return solveMem(i+1,j+1,a,b,dp);
        else{
            int insert = 1 + solveMem(i,j+1,a,b,dp);

            int del = 1 + solveMem(i+1,j,a,b,dp);

            int replace = 1 + solveMem(i+1,j+1,a,b,dp);

            ans = min({insert,del,replace});
        }

        return dp[i][j] = ans;
    }

    int solveTab(string a, string b){

        int n1 = a.size();
        int n2 = b.size();

        vector<vector<int>> dp(n1+2, vector<int>(n2+2,0));

        //Base case 1
        for(int j = 0; j<b.size();j++){
            dp[n1][j] = b.size()-j;
        }
        
        //Base case 2
        for(int i = 0; i<a.size();i++){
            dp[i][n2] = a.size()-i;
        }   

        for(int i = n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                
                int ans = 0;
                if(a[i]==b[j])
                    ans = dp[i+1][j+1];
                else{
                    int insert = 1 + dp[i][j+1];

                    int del = 1 + dp[i+1][j];

                    int replace = 1 + dp[i+1][j+1];

                    ans = min({insert,del,replace});
                }
                dp[i][j] = ans;
            }
        }
    
    return dp[0][0];

}
    int minDistance(string word1, string word2) {
            int n1 = word1.size();
            int n2 = word2.size();

            vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

            //return solve(word1,word2,0,0,dp);
            //return solveMem(0,0,word1,word2,dp);
            return solveTab(word1,word2);
    }

int main(){
    string word1 = "horse", word2 = "ros";
    cout<<minDistance(word1,word2)<<endl;
    
    return 0;
}