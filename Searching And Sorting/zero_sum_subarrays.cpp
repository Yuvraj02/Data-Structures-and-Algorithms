#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){

    vector<int> A = {0,0,5,5,0,0};
    unordered_map<int,int> mapp;

    mapp[0] = 1;
    int sum=0,count=0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];

        auto it = mapp.find(sum);

        if(it != mapp.end()){
            count+=it->second;
            it->second++;
        }else{
            mapp.insert(make_pair(sum,1));
        }

    }
    cout<<count;
    return 0;
}