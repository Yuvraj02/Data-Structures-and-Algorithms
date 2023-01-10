#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<int> A,int k, int mid){
    int cowCount = 1;
    int lastCow = A[0];

    for(int i = 0; i<A.size();i++){

        if(A[i]-lastCow>=mid){
                cowCount++;
                lastCow = A[i];
                if(cowCount == k){
                    return true;
                }
        }
    }
return false;
}

int aggressiveCows(vector<int> A, int k){

    sort(A.begin(),A.end());

    int s = 0;
    int maxi = INT32_MIN;
    
    for (int i = 0; i < A.size(); i++)
    {
       maxi = max(maxi,A[i]);
    }
    int e = maxi;
    int mid = s + (e-s)/2;
    
   int ans = -1;
    while (s<=e)
    {
        if(isPossibleSolution(A,k,mid)){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    
return ans;
}


int main(){

    vector<int> A = {4,2,1,3,6};
    int k = 2;

    cout<<aggressiveCows(A,k);
    return 0;
}