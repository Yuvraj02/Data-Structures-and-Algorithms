#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){

vector<vector<int>> A = {{1, 2, 3, 4, 5},
                    {2, 4, 5, 8, 10},
                    {3, 5, 7, 9, 11},
                    {1, 3, 5, 7, 9},
                  };

unordered_map<int,int> mapp;

for (int i = 0; i < A.size(); i++)
{
    for (int j = 0; j < A[i].size(); j++)
    {
        
        auto it = mapp.find(A[i][j]);
        if(it==mapp.end()){
            mapp.insert(make_pair(A[i][j],1));
        }else{
            it->second++;
        }
    }
}

    auto it = mapp.begin();
    int common=-1;
    while (it!=mapp.end())
    {
        if (it->second == A.size())
            common = it->first;
        it++;
    }
    
cout<<common;

}