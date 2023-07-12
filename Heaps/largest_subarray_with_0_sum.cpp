#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mapp;
        int maxLength = 0;
        int sum = 0;
        
        for(int i = 0; i<n;i++){
            sum+=A[i];
            if(sum==0){
                maxLength = i+1;
            }else{
                if(mapp.find(sum) != mapp.end()){
                    maxLength = max(maxLength, i-mapp[sum]);
                }else{
                    mapp[sum] = i;
                }
            }
        }
        return maxLength;
    }

int main(){

    vector<int> A = {15,-2,2,-8,1,7,10,23};
    cout<<maxLen(A,A.size());
    return 0;
}