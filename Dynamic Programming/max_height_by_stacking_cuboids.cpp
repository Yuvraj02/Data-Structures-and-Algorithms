#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 bool check(vector<int> base, vector<int> newBox){
        if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
            return true;

        return false;
    }

int maxHeight(vector<vector<int>>& cuboids) {
        for (auto &a : cuboids)
            sort(a.begin(),a.end());

    sort(cuboids.begin(),cuboids.end());

    int n = cuboids.size();

    vector<int> currentRow (n+1, 0);
        vector<int> next(n+1, 0);

        for(int curr = n-1; curr>=0;curr--){
            for(int prev = curr-1; prev>=-1;prev--){

                int include = 0;
                if(prev==-1 || check(cuboids[curr],cuboids[prev]))
                    include = cuboids[curr][2] + next[curr+1];
                
                int exclude = next[prev+1];

                currentRow[prev+1] = max(include,exclude);
            }
            next = currentRow;
        }
    return next[0];
}

int main(){

    vector<vector<int>> cuboids = {{50,45,20},{95,37,53},{45,23,12}};
    cout<<maxHeight(cuboids);
    return 0;
}
