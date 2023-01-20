#include <iostream>
#include <vector>

using namespace std;


int firstOccurence(vector<int> A, int start, int end, int key,int ans){

if(start>end)
    return ans;

int mid = start + (end-start)/2;

    if(A[mid]==key){
        ans = mid;
        return firstOccurence(A,start,mid-1,key,ans);
    }
    if(key<A[mid])
        return firstOccurence(A,start,mid-1,key,ans);

    if(key>A[mid])
        return firstOccurence(A,mid+1,end,key,ans);

return ans;
}

int lastOccurence(vector<int> A, int start, int end, int key, int ans){

    if(start>end){
        return ans;
    }

    int mid = start+(end-start)/2;

    if(A[mid]==key){
        ans = mid;
        return lastOccurence(A,mid+1,end,key,ans);
    }
    if(key<A[mid])
        return lastOccurence(A,start,mid-1,key,ans);
    if(key>A[mid])
        return lastOccurence(A,mid+1,end,key,ans);

return ans;
}


int main(){

    vector<int> A = {11,12,20,30,31,31,31,40,44,44};

    int key = 44;
    int ans = -1;
    int firstPos = firstOccurence(A,0,A.size()-1,key,ans);    
    int lastPos = lastOccurence(A,0,A.size()-1,key,ans);

    cout<<firstPos<<endl;
    cout<<lastPos;
    return 0;
}