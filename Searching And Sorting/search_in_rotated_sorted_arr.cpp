#include <iostream>
#include <vector>

using namespace std;


 int search(vector<int>& A, int target) {
        int start = 0, end = A.size()-1,mid=start + (end-start)/2;

        while(start<=end){
            if(A[mid]==target){
                return mid;
            }else if(A[start]<=A[mid]){
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
            mid = start + (end-start)/2;
        }
    return -1;
    }


int main(){

vector<int> A = {4,5,6,7,0,1,2};
int target = 0;
cout<<search(A,target)<<endl;

}