#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <utility>
#include <queue>

using namespace std;
 
 pair<int,int> sqToRowAndCol(int square,int n){

        int row = (square-1)/n;
        int col = (square-1)%n;

            if(row%2==1)
                col = n-1-col;
        
        return {row,col};
    }


    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
       
       reverse(board.begin(),board.end());
       vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        
        pair<int,int> src = {1,0};

        queue<pair<int,int>> q;
        q.push(src);

        visited[0][0] = true;

        while(!q.empty()){
            pair<int,int> front = q.front();
            q.pop();

            for(int i = 1; i<=6; i++){

                int nextSquare = front.first + i;
                pair<int,int> rowAndCol = sqToRowAndCol(nextSquare,n);
                int row = rowAndCol.first;
                int col = rowAndCol.second;

               
                if(board[row][col] != -1){
                    nextSquare = board[row][col];
                }
                 if(nextSquare == n*n)
                    return front.second + 1;
                
                if(!visited[row][col]){
                    visited[row][col] = true;
                    q.push({nextSquare,front.second+1});
                }
            }    
        }
        
        return -1;
    }