#include <iostream>
#include <vector>

using namespace std;

bool isPossibleHeight(vector<int> A, int req, int height){

    int remaining = req;

    for (int i = 0; i < A.size(); i++)
    {
        if(A[i]<=height)
            continue;
       
        remaining -= A[i]-height;
        
        if(remaining<=0){
            return true;
        }
    }
    return false;
}


int minBladeHeight(vector<int> A, int req){

int start = 0,end=INT32_MIN;

    for (int i = 0; i < A.size(); i++)
    {
        end = max(end,A[i]);
    }
    
    int mid = start + (end-start)/2;
    int ans = -1;
    while (start<=end)
    {
        if(isPossibleHeight(A,req,mid)){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;

}

int main(){
    int requirement,n;
    cin>>n>>requirement;
    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    
    cout<<minBladeHeight(A,requirement);

    return 0;
}