#include <iostream>
#include <vector>
#include <stack>
using namespace std;

 int celebrity(vector<vector<int> >& M, int n) 
    {
        //Step 1: Push all members to stack
        stack<int> s;
        for(int i=0 ;i <n ;i++) s.push(i);
        
        //Step 2: Eliminate normal peeps
        while(s.size() > 1){
            
            //Get top two peeps and compare
            int a = s.top();s.pop();
            int b = s.top();s.pop();
            
            //Compare these peeps
            //Discard a if a knows b
            if(M[a][b]==1)
                s.push(b);
            else
                s.push(a);
        }
        
        //Step 3: check if the candidate is a celebrity or not
        int candidate = s.top();
        bool rowCheck = true, colCheck = true;
        
        for(int i=0; i<n;i++){
            if(i==candidate) continue;
            //Check for column
            if(M[candidate][i]==1) colCheck = false;
            //Check for row
            if(M[i][candidate]==0) rowCheck = false;
            
        }
        
        if(rowCheck && colCheck)
            return candidate;
        else
            return -1;
    }

int main(){

    vector<vector<int>> matrix = {{0,1,0},
                                  {0,0,0},
                                  {0,1,0}};

     cout<<celebrity(matrix,matrix.size());
}