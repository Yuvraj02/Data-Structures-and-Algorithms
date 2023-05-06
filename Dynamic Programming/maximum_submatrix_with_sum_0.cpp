#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int zeroSum(vector<int> A, int &startingColumn, int &endingColumn){

    int sum = 0;
    int maxLen = 0;

    unordered_map<int,int> mapp;

    for(int i=0;i<A.size();i++){
        sum+=A[i];

        if(sum==0){
            startingColumn = 0;
            endingColumn = i;
            maxLen = i+1;
        }

        if(mapp.find(sum) == mapp.end()){
            mapp[sum] = i;
        }else{
            if(i - mapp[sum] + 1 >= maxLen){
                maxLen = i - mapp[sum] + 1;
                startingColumn = mapp[sum]+1;
                endingColumn = i;
            }
        }

    }
    return maxLen;
}

int main(){

    vector<vector<int>> A = {{27, 21, -22, -48},
                             {-38 ,-10 ,-40, 40},
                               { 42, 6 ,-15 ,-35}};

    int final_up = 0,final_down = 0, final_right = 0, final_left = 0;

    int startingColumn = 0,endingColumn =0;
    int maxArea = INT_MIN;
    int R = A.size();
    int C = A[0].size();
    int maxLen = 0;

    for(int row1=0;row1<R;row1++){
        vector<int> adder (C,0);
        for(int row2=row1;row2<R;row2++){

            for(int i=0;i<C;i++)
                adder[i] += A[row2][i];

            int currLen = zeroSum(adder,startingColumn,endingColumn);
            int area = (endingColumn-startingColumn+1)*(row2-row1+1);

            if(currLen > maxLen && area > maxArea){
                final_up = row1;
                final_down = row2;
                final_left = startingColumn;
                final_right = endingColumn;
                maxLen = currLen;
                maxArea = area;
            }

        }
    }

    for(int i=final_up;i<=final_down;i++){
        for(int j = final_left;j<=final_right;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}