#include <iostream>
#include <vector>

using namespace std;

bool isSafeToGo(vector<vector<int>> &maze, int n, int newx,  int newy, vector<vector<int>>& helperMaze){
        if((newx>=0 && newx<n) && (newy>=0 && newy<n) && maze[newx][newy]==1 && helperMaze[newx][newy]==0)
            return true;
            
        return false;
    }
    
    void solve(vector<vector<int>>&maze, int n, int x, int y, string output,vector<string>& ans,vector<vector<int>>&helperMaze){
        
        if(x==n-1 && y==n-1){
            ans.push_back(output);
            return;
        }
        
        helperMaze[x][y] = 1;
        
        //Go down
        int newx = x+1;
        int newy = y;
        if(isSafeToGo(maze,n,newx,newy,helperMaze)){
            output.push_back('D');
            solve(maze,n,newx,newy,output,ans,helperMaze);
            output.pop_back();
        }
        
        //Go left
        newx = x;
        newy = y-1;
        if(isSafeToGo(maze,n,newx,newy,helperMaze)){
            output.push_back('L');
            solve(maze,n,newx,newy,output,ans,helperMaze);
            output.pop_back();
        }
        
        //Go right
        newx = x;
        newy = y+1;
        if(isSafeToGo(maze,n,newx,newy,helperMaze)){
            output.push_back('R');
            solve(maze,n,newx,newy,output,ans,helperMaze);
            output.pop_back();
        }
        
        //Go Up
        newx = x-1;
        newy = y;
        if(isSafeToGo(maze,n,newx,newy,helperMaze)){
            output.push_back('U');
            solve(maze,n,newx,newy,output,ans,helperMaze);
            output.pop_back();
        }
        
        helperMaze[x][y]=0;
            
    }

     vector<string> findPath(vector<vector<int>> &m, int n) {

        vector<string> path;
        if(m[0][0]==0)
            return path;
        vector<vector<int>> helperMaze(n,vector<int>(n,0));
        
        string output="";
        
        solve(m,n,0,0,output,path,helperMaze);
        
        return path;
    }

    int main(){

        vector<vector<int>> maze = {{1, 0, 0, 0},
                                    {1, 1, 0, 1}, 
                                    {1, 1, 0, 0},
                                    {0, 1, 1, 1}};
        int N = maze.size();
        vector<string> paths = findPath(maze,N);

        for(auto i : paths){
            cout<<i<<" ";
        }

        return 0;
    }