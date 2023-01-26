#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> &board, int newX, int newY,int n){
    return ((newX>=0 && newX<n) && (newY>=0 && newY<n) && board[newX][newY]==-1);
}

bool solve(vector<vector<int>> &board, int x,int y ,vector<int> moveX, vector<int> moveY, int movei,int n){

    if(movei == n*n)
        return true;

    for (int i = 0; i < 8; i++)
    {
        int newX = x+moveX[i];
        int newY = y+moveY[i];
        if(isSafe(board,newX,newY,8)){
            board[newX][newY]=movei;
            bool furtherSolution = solve(board,newX,newY,moveX,moveY,movei+1,n);
            if(furtherSolution)
                return true;
            else
            board[newX][newY]=-1;
        }
    }
   
return false;
}

int main(){

    int N = 8;
    vector<vector<int>> board(N, vector<int>(N, -1));
    int x = 0,y=0;
    int move=0;
    vector<int> xMove = { 2, 1, -1, -2, -2, -1,  1,  2 };
    vector<int> yMove = { 1, 2,  2,  1, -1, -2, -2, -1 };
    board[0][0]=0;
    solve(board,x,y,xMove,yMove,1,N);
    for (int i = 0; i < N; i++)
    {
        for(int j=0;j<N;j++){
            cout<<"  "<<board[i][j];
        }
        cout<<endl;
    }

    return 0;
}