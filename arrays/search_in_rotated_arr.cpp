#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> A, int target){

   int left = 0;
   int right = A.size()-1;
   int mid;

   while (left<=right)
   {
        mid = (left+right)/2;

        if(target==A[mid]){
            return mid;
        }else if(A[mid]>=A[left]){
            if(target<=A[mid] && target>=A[left]){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }else{
            if(target>=A[mid] && target<=A[right]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
            
   }
    
    return -1;
}

int main(){

    vector<int> A = {4,5,6,7,8,0,1,2};
    int target = 0;
    cout<<binarySearch(A,target);

    return 0;
}