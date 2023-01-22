#include <iostream>
#include <vector>
using namespace std;

bool isCorrectValue(int row,int column, vector<vector<int>> &board,int value,int n){

    for(int i=0;i<n;i++){
        if(board[row][i]==value)
            return false;
        
        if(board[i][column]==value)
            return false;

        if(board[3*(row/3)+i/3][3* (column/3)+i%3]==value)
            return false;
    }    
return true;
}

bool solve(vector<vector<int>> &board,int n){

    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < n; column++)
        {
                if(board[row][column]==0){
                    for (int i = 1; i <= 9; i++)
                    {
                        if(isCorrectValue(row,column,board,i,n)){
                            board[row][column]=i;
                            bool isPossibleSolution = solve(board,n);

                            if(isPossibleSolution)
                                return true;
                            else
                            board[row][column]=0;
                        }
                    }
                    return false;
                }
        }
        
    }
return true;
}

int main(){

    vector<vector<int>> sudoku = {{3 ,0 ,6 ,5 ,0 ,8 ,4 ,0 ,0},
                                  {5 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
                                  {0 ,8 ,7 ,0 ,0 ,0 ,0 ,3 ,1},
                                  {0 ,0 ,3 ,0 ,1 ,0 ,0 ,8 ,0},
                                  {9 ,0 ,0 ,8 ,6 ,3 ,0 ,0 ,5},
                                  {0 ,5 ,0 ,0 ,9 ,0 ,6 ,0 ,0},
                                  {1 ,3 ,0 ,0 ,0 ,0 ,2 ,5 ,0},
                                  {0 ,0 ,0 ,0 ,0 ,0 ,0 ,7 ,4},
                                  {0 ,0 ,5 ,2 ,0 ,6 ,3 ,0 ,0}};

    vector<vector<int>> ans;

    solve(sudoku,9);                              

    return 0;
}