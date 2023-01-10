#include <iostream>
#include <vector>

using namespace std;

bool isPossibleSolution(vector<int> A, int n, int k, int mid){

   int painterCount=1,time = 0;

    for (int i = 0; i < n; i++)
    {
        if(time+A[i]<=mid){
            time+=A[i];
        }else{
            painterCount++;
            if(painterCount>k || A[i]>mid){
                return false;
            }
            time = A[i];
        }
    }
    return true;
}


int minTime(vector<int>&A, int n, int k){

    int start = 0,end=0;
    for (int i = 0; i < n; i++)
    {
        end+=A[i];
    }
    
    int mid = start + (end-start)/2;
    int ans = -1;
    while (start<=end)
    {
        if(isPossibleSolution(A,n,k,mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    mid = start + (end-start)/2;
    }
return ans;
}

int main(){

vector<int> A = {5,5,5,5};
int k =2;

cout<<minTime(A,A.size(),k)<<endl;

}