#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> A, int x, int y, vector<vector<int>>& helperMaze){

    if(A[x][y]==0 || helperMaze[x][y]==1)
        return false;

return true;
}

bool isValid(int n,int m, int x, int y){

    if((x>=0 && x<n) && (y>=0 && y<m))
        return true;
    
    return false;
}

void markUnsafeCells(vector<vector<int>>& A, vector<int> xMove, vector<int> yMove){

//Mark the Adjacent cells with landmine
for (int i = 0; i < A.size(); i++)
{
    for (int j = 0; j < A[0].size(); j++)
    {
        if(A[i][j]==0){
            for(int k = 0; k<4;k++){
                    if(isValid(A.size(),A[0].size(),i+xMove[k],j+yMove[k]))
                        A[i+xMove[k]][j+yMove[k]]=-1;
            }
        }
    }
}

for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]==-1)
                A[i][j]=0;
        }
    }

}

void solve(vector<vector<int>> A, int x, int y, vector<vector<int>> &helperMaze,vector<int> moveX,vector<int> moveY,int &shortestPath,int count){
   
    if(y==A[0].size()-1){
        //reached state
       // cout<<"Found";
        shortestPath = min(count,shortestPath);
        return;
    }

    helperMaze[x][y] = 1;
    
    for (int i = 0; i < 4; i++)
    {
        int next_x = x+moveX[i];
        int next_y = y+moveY[i];
        if(isValid(A.size(),A[0].size(),next_x,next_y) && isSafe(A,next_x,next_y,helperMaze)){
            //cout<<"Nope";
            solve(A,next_x,next_y,helperMaze,moveX,moveY,shortestPath,count+1);
        }
    }
    
    helperMaze[x][y]=0;

}

int main(){

    vector<vector<int>> A = {{ 1  ,1 , 1 , 1 , 1 , 1 , 1 , 1 , 1,  1,},
                             { 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1,},
                             { 1 , 1 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 },
                             { 1 , 1 , 1 , 1 , 0 , 1 , 1 , 1 , 1 , 1 },
                             { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
                             { 1 , 1 , 1 , 1 , 1 , 0 , 1 , 1 , 1 , 1 },
                             { 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 1 },
                             { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
                             { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
                             { 0 , 1 , 1 , 1 , 1 , 0 , 1 , 1 , 1 , 1 },
                             { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
                             { 1 , 1 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 }};

    vector<vector<int>> helperMaze (A.size(), vector<int>(A[0].size(),0));
    vector<int> moveX = {0, 0, 1,-1};
    vector<int> moveY = {1,-1, 0, 0};
        
    int shortestPath = INT32_MAX;
    int count = 0;
    
    markUnsafeCells(A,moveX,moveY);

    for (int i = 0; i < A.size(); i++)
    {
         if(A[i][0]==1)
            solve(A,i,0,helperMaze,moveX,moveY,shortestPath,count);
    }

    cout<<shortestPath;
    return 0;
}