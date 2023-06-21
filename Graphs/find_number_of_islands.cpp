 #include <iostream>
 #include <vector>
 
 using namespace std;
 
 bool isSafe(int x, int y, int n, int m){
        
        if((x>=0 && x<n) && (y>=0 && y<m))
            return true;
        return false;
    }
    
    void dfs(int x,int y,int n,int m,vector<vector<char>> &grid, vector<vector<bool>>&visited,int X[], int Y[]){
      
      visited[x][y] = true;
      
      for(int i = 0; i<8;i++){
          
          int nextX = x + X[i];
          int nextY = y + Y[i];
          
          if(isSafe(nextX,nextY,n,m) && !visited[nextX][nextY] && grid[nextX][nextY]=='1'){
              dfs(nextX,nextY,n,m,grid,visited,X,Y);
          }
          
      }
            
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        int X[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int Y[] = {1, 1, 0,-1,-1, -1,  0,  1};
        
        vector<vector<char>>&helperGrid = grid;
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        int islands = 0;
        
        for(int i = 0; i<n ;i++){
            for(int j = 0; j<m ;j++){
               
                if(!visited[i][j] && grid[i][j]=='1'){
                    
                    dfs(i,j,n,m,helperGrid,visited,X,Y);
                    
                    islands++;
                }
            }
        }
        return islands;
    }