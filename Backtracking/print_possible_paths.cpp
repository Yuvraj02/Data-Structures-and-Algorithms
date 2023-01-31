#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int n, int m, int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}

void solve(vector<vector<int>> A, vector<vector<int>> &ans, int x, int y,vector<int> path){

    if(x==A.size()-1 && y==A[0].size()-1){
        path.push_back(A[x][y]);
        ans.push_back(path);
        path.pop_back();
        return ;
    }

    path.push_back(A[x][y]);

    //Go Right
    int next_x = x;
    int next_y = y+1;
    if(isSafe(A.size(),A[0].size(),next_x,next_y)){
        solve(A,ans,next_x,next_y,path);
    }

    //Go Down
    next_x = x+1;
    next_y = y;
    if(isSafe(A.size(),A[0].size(),next_x,next_y)){
        solve(A,ans,next_x,next_y,path);
    }
    
    path.pop_back();

}

int main(){

    vector<vector<int>> A = {{1,2,3},
                             {4,5,6},
                             {7,8,9}};

    vector<vector<int>> ans;
    vector<int> path;
    solve(A,ans,0,0,path);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<"[";
        for(int j = 0; j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    

    return 0;
}