#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int> > & a, vector<vector<int>> &T, int curr_line, int curr_pos, vector<int> &x,vector<vector<int>> &dp){
    
    if(curr_pos >= a[0].size()-1){
        
        return a[curr_line][curr_pos] + x[curr_line];
    }
    
    if(dp[curr_line][curr_pos]!=-1)
        return dp[curr_line][curr_pos];
        
    //Now 2 options
    //1. Go Straight
    //cout<<curr_pos<<endl;
    int option1 = a[curr_line][curr_pos] + solve(a,T,curr_line,curr_pos+1,x,dp);
    
    //2. Change Direction
    int option2 = T[curr_line][curr_pos+1] + a[curr_line][curr_pos] + solve(a,T,!curr_line,curr_pos+1,x,dp);
    
    return dp[curr_line][curr_pos] = min(option1,option2);
      
  }
    
  int solveTab(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
     int n = a.size();
     int m = a[0].size();
     vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
     
     for(int i=0;i<n;i++){
         dp[i][m-1] = a[i][m-1] + x[i];
     }
     
    int curr_line = 0;
     
    for(int curr_pos = m-2 ; curr_pos>=0; curr_pos--){
        
        for(int curr_line = 0; curr_line<=1; curr_line++){
            
            int option1 = a[curr_line][curr_pos] + solve(a,T,curr_line,curr_pos+1,x,dp);
            
            int option2 = T[curr_line][curr_pos+1] + a[curr_line][curr_pos] + dp[!curr_line][curr_pos+1];
            
            dp[curr_line][curr_pos] = min(option1,option2);
        }
        
    }
     
     
     for(int curr_pos = m-2 ; curr_pos>=0; curr_pos--){
        
        for(int curr_line = 1; curr_line>=0; curr_line--){
            
            int option1 = a[curr_line][curr_pos] + solve(a,T,curr_line,curr_pos+1,x,dp);
            
            int option2 = T[curr_line][curr_pos+1] + a[curr_line][curr_pos] + dp[!curr_line][curr_pos+1];
            
            dp[curr_line][curr_pos] = min(option1,option2);
        }
        
    }
     
    int startWithA = e[0] + dp[0][0];
    int startWithB = e[1] + dp[1][0];
    
    
    return min(startWithA,startWithB);
     
  }
  
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      //Code Here
    //  int n = a.size();
    //  int m = a[0].size();
    //  vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
      
    // int startWithA = e[0] + solve(a,T,0,0,x,dp);
    // int startWithB = e[1] + solve(a,T,1,0,x,dp);
    
    //return min(startWithA,startWithB);
    return solveTab(a,T,e,x);
  }

  int main(){

    int N = 4;
    vector<vector<int>> a = {{4, 5, 3, 2}, 
                    {2,10,1, 4}};
    
    vector<vector<int>> T = {{0,7, 4, 5},
                             {0,9, 2, 8}};

    vector<int> e = {10,12}, x = {18,7};

    cout<<carAssembly(a,T,e,x);

  }