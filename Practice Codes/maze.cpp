#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &helperMaze){
        
        if((x>=0 && x<maze.size()) && (y>=0 && y<maze[0].size()) && (maze[x][y]!=0) && helperMaze[x][y]==0)
            return true;

    return false;
        
}

void solve(vector<vector<int>>& maze,int x, int y,int n,int m, vector<int> X_moves, vector<int> Y_moves, vector<vector<int>>& helperMaze, int length,int &shortestLength){
    
    if(x==n && y==m){
       shortestLength = max(shortestLength,length);
        return;
    }
    
    helperMaze[x][y]=1;
    //cout<<"w";

    for(int i=0; i<X_moves.size();i++){
            int next_x = x + X_moves[i];
            int next_y = y + Y_moves[i];
            //cout<<next_x<<" "<<next_y<<endl;
            if(isSafe(maze,next_x,next_y,helperMaze)){
                //cout<<"Yes"<<endl;
                solve(maze,next_x,next_y,n,m,X_moves,Y_moves,helperMaze,length+1,shortestLength);
            }
    }
    //cout<<"A";
    helperMaze[x][y] = 0;
}

int minMoves(vector<vector<int>> maze, int n, int m) {

    int rows = maze.size();
    int cols = maze[0].size();
    
    vector<vector<int>> helperMaze(rows,vector<int>(cols, 0));

    vector<int> X_moves = { 0,1,0,-1};
    vector<int> Y_moves = {-1,0,1, 0};

    int shortestLength = INT32_MIN;
    
    solve(maze,0,0,n,m,X_moves,Y_moves,helperMaze,0,shortestLength);
    return shortestLength;
}

int main(){

    vector<vector<int>> maze = {{1,2,1},
                                {1,1,0},
                                {0,0,0}};
    int n= 1,m=1;

    cout<<minMoves(maze,n,m)<<endl;

}