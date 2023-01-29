#include <iostream>
#include <vector>
using namespace std;


bool isSafeMove(vector<vector<int>>& A,int x, int y, vector<vector<int>> &helperMaze){

    if((x>=0 && x<A.size()) && (y>=0 && y<A[0].size())){

        if(A[x][y]==0)
            return false;
        //Check For directions
        
        //Check for right side
        if(y+1<A[0].size() && A[x][y+1]!=1)
            return false;
        //Check For Down side
        if(x+1<A.size() && A[x+1][y]!=1)
            return false;
        //Check for Left side
        if(y-1>=0 && A[x][y-1]!=1)
            return false;
        //Check for upside
        if(x-1>=0 && A[x-1][y]!=1)
            return false;

        if(helperMaze[x][y]!=0)
            return false;
    }else{
        return false;
    }

    return true;
}

void solve(vector<vector<int>> A, int x, int y, vector<vector<int>> &helperMaze,vector<int> moveX,vector<int> moveY,int &shortestPath,int &count){

    if(y==A[0].size()-1){
        //reached state
        shortestPath = min(count,shortestPath);
        return;
    }

    for (int row = x; row < A.size(); row++)
    {
        //Check for all directions
        for (int k = 0; k < 4; k++)
        {
            int next_X = row + moveX[k];
            int next_Y = y + moveY[k];
            if(isSafeMove(A,next_X,next_Y,helperMaze)){
                count++;
                helperMaze[next_X][next_Y]=1;     
                solve(A,next_X,next_Y,helperMaze,moveX,moveY,shortestPath,count);
                helperMaze[next_X][next_Y] = 0;
                count--;
            }

        }
    }

}

int main(){

    vector<vector<int>> A = {{1,0,1,1,1},
                             {1,1,1,1,1},
                             {1,1,1,1,1},
                             {1,1,1,0,1},
                             {1,1,1,1,0}};
    vector<vector<int>> helperMaze (A.size(), vector<int>(A[0].size(),0));

    vector<int> moveX = {0, 0, 1,-1};
    vector<int> moveY = {1,-1, 0, 0};
        
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            cout<<helperMaze[i][j]<<" ";
        }
        cout<<endl;
    }  

    int shortestPath = INT32_MAX;
    int count = 1;
    solve(A,0,0,helperMaze,moveX,moveY,shortestPath,count);
    cout<<shortestPath;
    return 0;
}