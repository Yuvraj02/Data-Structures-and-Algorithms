#include <iostream>
#include <vector>
using namespace std;

bool isCorrectValue(vector<vector<char>>& sudoku, int row,int column,int n,char value){

    for (int i = 0; i < n; i++)
    {
        //Check if value is unique in row
        if(sudoku[row][i]==value)
            return false;
        //Check if value is unique in column
        if(sudoku[i][column]==value)
            return false;
        
        //Check for 3x3 matrix
        if(sudoku[3*(row/3)+i/3][3*(column/3)+i%3]==value)
            return false;
    }
return true;
}

bool solveSudoku(vector<vector<char>>& sudoku){

    int n = sudoku.size();

    for(int row = 0; row<n;row++){
        for(int column = 0; column<n;column++){
                if(sudoku[row][column]=='.'){
                    for(int i = 1; i<=9;i++){
                        char value = (i+'0');
                        if(isCorrectValue(sudoku,row,column,n,value)){
                            sudoku[row][column]=value;
                            bool furtherSolution = solveSudoku(sudoku);
                            if(furtherSolution)
                                return true;
                            else
                                sudoku[row][column]='.';
                        }
                    }
                    return false;
                }
        }
    }
    return true;
}

int main(){
    vector<vector<char>> sudoku = {{'5','3','.', '.','7','.', '.','.','.'},
                                   {'6','.','.', '1','9','5', '.','.','.'},
                                   {'.','9','8', '.','.','.', '.','6','.'},
                                   
                                   {'8','.','.', '.','.','.', '.','.','3'},
                                   {'4','.','.', '8','.','3', '.','.','1'},
                                   {'7','.','.', '.','2','.', '.','.','6'},
                                   
                                   {'.','6','.', '.','.','.', '2','8','.'},
                                   {'.','.','.', '4','1','9', '.','.','5'},
                                   {'.','.','.', '.','8','.', '.','7','9'}};


    for (int i = 0; i < sudoku.size(); i++)
    {
        for(int j=0;j<sudoku.size();j++){
            if(j%3==0)
                cout<<"  ";

            cout<<sudoku[i][j]<<" ";
            
        }
        if(i==2 || i==5)
            cout<<"\n";

        cout<<endl;
    }
    
    solveSudoku(sudoku);
    cout<<"---------------------------"<<endl;
    for (int i = 0; i < sudoku.size(); i++)
    {
        for(int j=0;j<sudoku.size();j++){
            if(j%3==0)
                cout<<"  ";

            cout<<sudoku[i][j]<<" ";
            
        }
        if(i==2 || i==5)
            cout<<"\n";

        cout<<endl;
    }
   
    return 0;
}