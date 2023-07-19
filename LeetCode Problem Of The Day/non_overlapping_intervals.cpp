/*
Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

  int eraseOverlapIntervals(vector<vector<int>>& A) {
        sort(A.begin(),A.end());

        int interval = 0;
        int count = 0;
        for(int i = 1; i<A.size();i++){

            if(A[interval][1] > A[i][0]){
                A[i][1] = min(A[interval][1],A[i][1]);
                count++;
            }
            interval = i;
        }
        return count;
    }

int main(){

    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout<<eraseOverlapIntervals(intervals);
    return 0;
}