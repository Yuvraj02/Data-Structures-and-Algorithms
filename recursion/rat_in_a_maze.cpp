#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int newx,int newy,int n, vector<vector<int>>& maze,vector<vector<int>> &helperMaze){

    if((newx>=0 && newx<n) && (newy>=0 && newy<n) && maze[newx][newy]==1 && helperMaze[newx][newy]==0)
        return true;
    else
        return false;

}

void solve(vector<vector<int>>& maze, int x, int y,int n,string output,vector<string>& paths,vector<vector<int>> &helperMaze){

    if(x==n-1 && y==n-1){
        paths.push_back(output);
        return;
    }

    helperMaze[x][y] = 1;

    //Go Down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx,newy,n,maze,helperMaze)){
        output.push_back('D');
        solve(maze,newx,newy,n,output,paths,helperMaze);
        output.pop_back();
    }

    //Go right
    newx = x;
    newy = y+1;
    if(isSafe(newx,newy,n,maze,helperMaze)){
        output.push_back('R');
        solve(maze,newx,newy,n,output,paths,helperMaze);
        output.pop_back();
    }

    //Go Left
    newx = x;
    newy = y-1;
    if(isSafe(newx,newy,n,maze,helperMaze)){
        output.push_back('L');
        solve(maze,newx,newy,n,output,paths,helperMaze);
        output.pop_back();
    }

    //Go Up
    newx = x-1;
    newy = y;
    if(isSafe(newx,newy,n,maze,helperMaze)){
        output.push_back('U');
        solve(maze,newx,newy,n,output,paths,helperMaze);
        output.pop_back();
    }

    helperMaze[x][y]=0;
    
}

int main(){

    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1}, 
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    int n = 4;

    vector<vector<int>> helperMaze(n,vector<int>(n,0));
    vector<string> path;
    string output = "";
    solve(maze, 0,0,n,output,path,helperMaze);

    for(auto i:path){
        cout<<i<<" ";
    }
    // for (int i = 0; i < maze.size(); i++)
    // {
    //     for(int j = 0; j<maze[i].size();j++){
    //         cout<<maze[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"\n";
    // for (int i = 0; i < maze.size(); i++)
    // {
    //     for(int j = 0; j<maze[i].size();j++){
    //         cout<<helperMaze[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return 0;
}