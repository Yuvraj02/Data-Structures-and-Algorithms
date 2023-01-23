#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> A, int sum,int k,int currentVal,vector<int> output,vector<vector<int>> &ans){

    if(sum==k){
        ans.push_back(output);
        return;
    }

    for(int i=currentVal;i<A.size();i++){
        if(sum+A[i]<=k){
            sum+=A[i];
            output.push_back(A[i]);
            solve(A,sum,k,i,output,ans);
            output.pop_back();
            sum-=A[i];
        }
    }

}

int main(){

    vector<int> A = {2,3,6,7};
    int k = 7;
    vector<vector<int>> ans;
    vector<int> output;
    solve(A,0,k,0,output,ans);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
        
    }
    

    return 0;
}