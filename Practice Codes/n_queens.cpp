#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int column, int n){

    int i=row,j=column-1;

    //Check for left
    while(j>=0){
        if(board[i][j]=='Q')
            return false;
        j--;
    }

    //Check for diagonal up left
    i=row-1,j=column-1;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q')
            return false;
        i--;
        j--;
    }

    //Check for diagonal down left
    i = row+1, j= column-1;

    while(i<n && j>=0){
        if(board[i][j]=='Q')
            return false;
        
        i++;
        j--;
    }

    return true;
}


void printBoard(vector<vector<char>> &board,int n){

    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
    }
}

void insertBoard(vector<vector<char>> &board, int n, vector<vector<string>> &ans){

    
    vector<string> currentBoard;
   for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+=board[i][j];
            }
        currentBoard.push_back(s);
    }

    ans.push_back(currentBoard);
}

void printAns(vector<vector<string>> ans){
        cout<<"[";
        for(int i=0;i<ans.size();i++){
                cout<<"[";
                for(int j=0;j<ans[i].size();j++){
                    cout<<ans[i][j]<<", ";
                }
                cout<<"],";
        }
        cout<<"]"<<endl;
}

void solve(vector<vector<char>> &board, int column, int n,vector<vector<string>> &ans,int &count){

    if(column==n){
        //Print board
        count++;
        cout<<"Solution : "<<count<<endl;
        printBoard(board,n);
       // insertBoard(board,n,ans);
        cout<<"---------------"<<endl;
        
    }

    for(int row=0;row<n;row++){
        if(isSafe(board,row,column,n)){
            board[row][column] = 'Q';
            solve(board,column+1,n,ans,count);
            board[row][column]='.';
        }
    }
}

int main(){ 

    int n;
    cin>>n;

    vector<vector<char>> board(n,vector<char>(n,'.'));
    vector<vector<string>> ans;
    int count = 0;
    solve(board,0,n,ans,count);
    printAns(ans);
    return 0;
}