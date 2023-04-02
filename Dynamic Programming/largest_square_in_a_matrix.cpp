#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<vector<int>> &A, int i, int j,int &maxSquare){
    if(i>=A.size() || j>=A[0].size()){
        return 0;
    }

    //Check for right side
    int right = solve(A,i,j+1,maxSquare);
    //Check for diagonal right
    int diagRight = solve(A,i+1,j+1,maxSquare);
    //Check for down
    int down = solve(A,i+1,j,maxSquare);

    if(A[i][j]==1){
        int ans = 1 + min({right,diagRight,down});
        //Store answer at each step
        maxSquare = max(maxSquare,ans);
        return ans;
    }else{
        return 0;
    }
}

int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
    int maxSquare = INT32_MIN;
    solve(mat,0,0,maxSquare);
    return maxSquare;

}

int main(){

    int n = 2, m=2;

    vector<vector<int>> A = {{1, 1}, 
                            {1, 1}};

    cout<<maxSquare(n,m,A);
    return 0;
}