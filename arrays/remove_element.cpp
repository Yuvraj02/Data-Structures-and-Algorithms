#include <iostream>
#include <vector>

using namespace std;


 int removeElement(vector<int>& nums, int val) {
        int i = 0,j=nums.size()-1;

        int count = 0;
        while(i<=j){
            if(nums[j]==val){
                count++;
                j--;
            }else if(nums[i]==val){
                count++;
                swap(nums[i],nums[j]);
                i++;
                j--;
            }else{
                i++;
            }
        }
        return nums.size()-count;
    }

int main(){

    vector<int> A = {0,1,2,2,3,0,4,2};
    int val = 2;
    int k = removeElement(A,val);
    for(int i = 0;i<k;i++){
        cout<<A[i]<<" ";
    }

    return 0;
}