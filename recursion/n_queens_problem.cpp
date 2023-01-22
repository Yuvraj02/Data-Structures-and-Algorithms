#include <iostream>
#include <vector>

using namespace std;

void addSolution(vector<vector<int>>&board,vector<vector<int>> &ans,int n){

    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int column, vector<vector<int>>&board,int n){

    int x=row,y=column;

    //Horizontally left
    while (y>=0)
    {
        if(board[x][y]==1)
            return false;
        
        y--;
    }
    
    //Diagonally left up
    x=row, y=column;
    while (x>=0 && y>=0)
    {
        if(board[x][y]==1)
            return false;
        
        x--;
        y--;
    }
    //Diagonally left down
    x=row, y=column;
    while (x<n && y>=0)
    {
        if(board[x][y]==1)
            return false;
        
        x++;
        y--;
    }
    
    return true;
}

void solve(vector<vector<int>>&board, int n, int column, vector<vector<int>> &ans){

    if(column==n){
        addSolution(board,ans,n);
        return ;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row,column,board,n)){
            //If it's safe then, place the queen and go to next column
            board[row][column] = 1;
            solve(board,n,column+1,ans);
            //Backtrack to remove queen and place on another column for next function call
            board[row][column]= 0;
        }
    }

}


int main(){

    int n = 4;
    vector<vector<int>> board (n, vector<int> (n,0));
    vector<vector<int>> ans;

    solve(board, n,0, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}