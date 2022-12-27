#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<vector<int>> A = {{0,0},{1,4}};

    vector<vector<int>> finalVec;

        sort(A.begin(),A.end());

        int start = A[0][0],end=A[0][1];

     for (int i = 1; i < A.size(); i++)
     {
        
            if(end>=A[i][0]){
              start = min(start,A[i][0]);
              end = max(end,A[i][1]);
            }else if (A[i][1]<=start){
              start = min(start,A[i][0]);
              end = max(end,A[i][1]);
            }else{
                finalVec.push_back({start,end});
                start=A[i][0];
                end=A[i][1];
            }

     }
    finalVec.push_back({start,end});

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