#include <iostream>
#include <vector>

using namespace std;

//Prepare Matrix
bool isValid(vector<vector<int>>& mat, int x, int y,int n,int m){

    return ((x>=0 && x<n) && (y>=0 && y<m) && mat[x][y]==1);

}

void markLandMines(vector<vector<int>>& mat, int n, int m, vector<int> moveX, vector<int> moveY){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j]==0){
                
                for (int k = 0; k < 4; k++)
                {   
                    int next_x = i + moveX[k];
                    int next_y = j + moveY[k];
                    if (isValid(mat,next_x,next_y,n,m))
                    {
                        //Do not mark as 0 becase in next iteration it will again treat 0 as a landmine
                            mat[next_x][next_y]=-1;
                    }
                    
                }
                

            }
        }
        
    }

    //Map -1 to 0 now
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j]==-1)
                mat[i][j]=0;
        }
        
    }
    
}


bool isSafe(vector<vector<int>>&mat, int x, int y,int n,int m, vector<vector<int>> &helperMaze){

    return ((x>=0 && x<n) && (y>=0 && y<m) && mat[x][y]==1 && helperMaze[x][y]==0);
}

void solve(vector<vector<int>> &mat,int &shortestPath, int x,int y, int count,vector<vector<int>> &helperMaze,int n, int m,vector<int> moveX, vector<int> moveY){

    if(y==m-1){
        shortestPath = min(count,shortestPath);
        return ;
    }
    helperMaze[x][y]=1;

    for (int i = 0; i < 4; i++)
    {
        int next_x = x+moveX[i];
        int next_y = y+moveY[i];
        if(isSafe(mat,next_x,next_y,n,m,helperMaze)){
            solve(mat,shortestPath,next_x,next_y,count+1,helperMaze,n,m,moveX,moveY);
        }
    }
    helperMaze[x][y]=0;
}


int findShortestPath(vector<vector<int>>&mat){

    int ROW = mat.size();
    int COL = mat[0].size();
    vector<vector<int>> helperMaze(ROW,vector<int>(COL,0));

    int shortestPath = INT32_MAX;
    int count=1;

    vector<int> moveX = {0, 0, 1, -1};
    vector<int> moveY = {1,-1, 0,  0};

    markLandMines(mat,ROW,COL,moveX,moveY);

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
           cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }


    for (int i = 0; i < ROW; i++)
    {
        if(mat[i][0]==0)
            continue;

        solve(mat,shortestPath,i,0,count,helperMaze,ROW,COL,moveX,moveY);

    }
    if(shortestPath==INT32_MAX) 
        return -1;
    else
        return shortestPath;
}

int main(){

    vector<vector<int>> mat =  {{1 ,1 ,0 ,1 ,1 ,0},
                                {1 ,1 ,1 ,1 ,1 ,1},
                                {1 ,1 ,1 ,1 ,1 ,1},
                                {1 ,1 ,1 ,0 ,0 ,1},
                                {1 ,1 ,1 ,1 ,1 ,1},
                                {1 ,1 ,1 ,0 ,1 ,1},
                                {1 ,0 ,1 ,1 ,1 ,0},
                                {1 ,0 ,1 ,1 ,1 ,1},
                                {1 ,1 ,1 ,1 ,1 ,1}};

    cout<<findShortestPath(mat);

    return 0;
}