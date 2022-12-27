#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int binarySearch(vector<int> A,int target){

    int start = 0;
    int end = A.size()-1;

    int mid;

    while (start<=end)
    {
        mid = (start+end)/2;

        if(A[mid]==target){
            return mid;
        }else if(A[mid] >= A[start]){
            if(target>=A[start] && target<=A[mid]){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }else{
            if(target>=A[mid] && target<=A[end]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
   return -1; 

}

pair<int,int> findPair(vector<int> A, int X){

    pair<int,int> p;
    int y;
        for (int i = 0; i < A.size(); i++)
        {
            y=binarySearch(A,X-A[i]);
            if(y!=-1){
                p = make_pair(A[i],X-A[i]);
            }
        }
        
        return p;
}


int main(){

    vector<int> A = {11,15,26,38,9,10};
    pair<int,int> p = findPair(A,35);
    cout<<p.first<<" "<<p.second;
    

    return 0;
}