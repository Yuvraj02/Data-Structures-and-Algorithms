#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){

    vector<int> A = {-1,1,-1,1};
    int sum = 0,maxLength;
    unordered_map<int,int> mapp;

    for(int i = 0;i<A.size();i++){

        sum+=A[i];
        if(sum==0){
            maxLength=i+1;
        }
        auto it = mapp.find(sum);

        if(it==mapp.end()){
            mapp.insert(make_pair(sum,i));
        }else{
            maxLength = max(maxLength,i - it->second);
        }
    }

    cout<<maxLength;

    return 0;
}