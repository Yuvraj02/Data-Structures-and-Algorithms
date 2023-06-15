#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class cell{
    public:
        int x;
        int y;
        int steps;
        cell(){}
        cell(int x,int y,int steps){
            this->x = x;
            this->y = y;
            this->steps = steps;
        }
};

bool isSafe(int x, int y, int n){

    if((x>=0 && x<n) && (y>=0 && y<n))
        return true;
    
    return false;
}

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){

    vector<vector<bool>> visited(N+1,vector<bool> (N+1,false));

    int X[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int Y[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	    

    cell c(KnightPos[0],KnightPos[1],0);
    queue<cell> q;
    visited[KnightPos[0]][KnightPos[1]] = true;
    q.push(c);

    while(!q.empty()){

        cell front = q.front();
        q.pop();

        if(front.x == TargetPos[0] && front.y == TargetPos[1])
            return front.steps;

        for(int i = 0; i<8;i++){

            int nextX = front.x + X[i];
            int nextY = front.y + Y[i];
        
        if(isSafe(nextX,nextY,N+1) && !visited[nextX][nextY]){
            visited[nextX][nextY] = true;
            q.push(cell(nextX,nextY,front.steps+1));
        }
        }

    }
    return -1;
}

int main(){

    int N = 6;
    vector<int> KnightPos =  {4, 5};
    vector<int> TargetPos =  {1, 1};

    std::cout<<minStepToReachTarget(KnightPos,TargetPos,N);

    return 0;
}
