#include <iostream>
#include <vector>

using namespace std;

bool isSafeMove(vector<vector<int>> &matrix, int newX, int newY,vector<vector<int>>&helperMaze){
    if((newX>=0 && newX<matrix.size()) && (newY>=0 && newY<matrix[0].size()) && matrix[newX][newY]==1 && helperMaze[newX][newY]==0)
        return true;

    return false;
}


void solve(vector<vector<int>> &matrix, int currentX,int currentY,int xd, int yd, string path,vector<vector<int>> &helperMaze,int &longestPath){

  //  cout<<currentX<<" "<<currentY<<endl;

    if(currentX==xd && currentY==yd){
        
        // ans.push_back(path);
        int currentPath = path.size();
        longestPath = max(longestPath,currentPath);
        return;
    }

    helperMaze[currentX][currentY] = 1;
    //Go Down
    int newx = currentX+1;
    int newy = currentY;
    if(isSafeMove(matrix,newx,newy,helperMaze)){
        path.push_back('D');
        solve(matrix,newx,newy,xd,yd,path,helperMaze,longestPath);
        //Backtrack
        path.pop_back();
    }

    //Go Up
    newx = currentX-1;
    newy = currentY;
    if(isSafeMove(matrix,newx,newy,helperMaze)){
        path.push_back('U');
        solve(matrix,newx,newy,xd,yd,path,helperMaze,longestPath);
        //Backtrack
        path.pop_back();
    }

    //Go Left
    newx = currentX;
    newy = currentY-1;
    if(isSafeMove(matrix,newx,newy,helperMaze)){
        path.push_back('L');
        solve(matrix,newx,newy,xd,yd,path,helperMaze,longestPath);
        //Backtrack
        path.pop_back();
    }

    //Go Right
    newx = currentX;
    newy = currentY+1;
    if(isSafeMove(matrix,newx,newy,helperMaze)){
        path.push_back('R');
        solve(matrix,newx,newy,xd,yd,path,helperMaze,longestPath);
        //Backtrack
        path.pop_back();
    }

    helperMaze[currentX][currentY]=0;
}

int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
    string path="";
    vector<vector<int>> helperMaze(matrix.size(),vector<int>(matrix[0].size(), 0));
    int longestPathNum = -1;
    solve(matrix,xs,ys,xd,yd,path,helperMaze,longestPathNum);
    return longestPathNum;
    }


int main(){

    vector<vector<int>> matrix = {{1,1,1,1,1,1,1,1,1,1},
                                  {1,1,0,1,1,0,1,1,0,1},
                                  {1,1,1,1,1,1,1,1,1,1}};

    int xs = 0,ys=0;
    int xd=1,yd=7;

    cout<<longestPath(matrix,xs,ys,xd,yd);Z

    return 0;
}