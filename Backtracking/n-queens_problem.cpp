#include <iostream>
#include <vector>
using namespace std;


void addSolution(vector<vector<char>>&board,int n, vector<vector<string>> &ans){
    string row="";
    vector<string> oneBoard;

    for (int i = 0; i < n; i++)
    {
        row = "";
        for(int j=0;j < n;j++){
                row+=board[i][j];
        }
        oneBoard.push_back(row);
    }
    
    ans.push_back(oneBoard);
}

bool isSafeToPlace(vector<vector<char>>&board, int row, int column,int n){

    //Check for left
    int i = row,j=column;
    while (j>=0)
    {
        if(board[i][j]=='Q')
            return false;
        
        j--;
    }
    
    //Check for Diagonal Up left
    i = row;
    j = column;
    while (i>=0 && j>=0)
    {
        if(board[i][j]=='Q')
            return false;
        
        i--;
        j--;
    }

    //Check for Diagonal Down Left
    i = row;
    j = column;

    while (i<n && j>=0)
    {
        if(board[i][j]=='Q')
            return false;

        i++;
        j--;
    }
    
    return true;
}

void solve(vector<vector<char>>&board, int n, int column,vector<vector<string>> &ans){

    if(column==n){
        addSolution(board,n,ans);
        //cout<<"Hm";
        return ;
    }

    for(int row = 0; row<n; row++){
        if(isSafeToPlace(board,row,column,n)){
                board[row][column]='Q';
                solve(board,n,column+1,ans);
                board[row][column]='.';
        }
    }

}


vector<vector<string>> solveNQueens(int n){

vector<vector<char>> board (n,vector<char>(n,'.'));

vector<vector<string>> ans;
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        cout<<board[i][j]<<" ";
    }
    cout<<endl;
    
}

solve(board,n,0,ans);

return ans;
}

int main(){

    int N;
    cin>>N;

    vector<vector<string>> ans = solveNQueens(N);   

    return 0;
}