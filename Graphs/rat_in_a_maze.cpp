#include <iostream>
#include <vector>

using namespace std;

  bool isSafe(int x, int y, vector<vector<int>> &helperMaze, vector<vector<int>> &m,int n){
        
        if((x>=0 && x < n) && (y>=0 && y<n) && helperMaze[y][x] == 0 && m[y][x] == 1)
            return true;
            
        return false;
    }
    
    void solve(int x, int y, vector<vector<int>> &helperMaze, vector<vector<int>> &m,int X[], int Y[],vector<string> &ans, string &dir,int n){
        
        if(x==n-1 && y==n-1){
           // cout<<"Reached";
            ans.push_back(dir);
            
        }
        
        helperMaze[y][x] = 1;
        
        for(int i = 0 ;i<4;i++){
           // cout<<"S";
            int newX = x + X[i];
            int newY = y + Y[i];
            if(isSafe(newX,newY,helperMaze,m,n)){
                switch(i){
                    case 0:
                        dir.push_back('D');
                        break;
                    case 1:
                        dir.push_back('R');
                        break;
                    case 2:
                        //cout<<"D";
                        dir.push_back('U');
                        break;
                    case 3:
                       // cout<<"L";
                        dir.push_back('L');
                        break;
                    default:
                        cout<<"Out Of Bounds direction"<<endl;
                        break;
                }
                //cout<<dir;
                solve(newX,newY,helperMaze,m,X,Y,ans,dir,n);
               
            }
            
        }
        
        dir.pop_back();
        helperMaze[y][x] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        if(m[0][0]==0)
            return {};
        
        vector<vector<int> > helperMaze(n,vector<int>(n,0));
                 //D R U  L
        int X[] = {0,1,0,-1};
        int Y[] = {1,0,-1,0};
        
        vector<string> ans;
        string dir = "";
        
        solve(0,0,helperMaze,m,X,Y,ans,dir,n);
            
        return ans;
    }



int main(){

    int n = 4;

    vector<vector<int>> m = {{1,0,0,0},
                             {1,1,0,1},
                             {1,1,0,0},
                             {0,1,1,1}};
    for(auto i : findPath(m,n))
        cout<<i<<" ";
    

    return 0;
}