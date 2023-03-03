#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<vector<int>> A = {{0,0},{1,4}};

       vector<vector<int>> finalVec;

        sort(A.begin(),A.end());

        int interval1 = 0;
        for (int i = 1; i < A.size(); i++)
            {
                if(A[interval1][1]>=A[i][0]){
                    A[interval1][1] = max(A[interval1][1],A[i][1]);
                }else{
                    finalVec.push_back({A[interval1][0],A[interval1][1]});
                    interval1=i;
            }
     }
    finalVec.push_back({A[interval1][0],A[interval1][1]});

    for (int i = 0; i < finalVec.size(); i++)
    {
        for (int j = 0; j < finalVec[i].size(); j++)
        {
            cout<<finalVec[i][j]<<" ";
        }
        cout<<"\n";
        
    }

    return 0;
}