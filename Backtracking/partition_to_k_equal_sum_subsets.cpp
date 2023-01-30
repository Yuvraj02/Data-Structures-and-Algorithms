//This approach will give TLE error, best approach requires DP

#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int> A, int target, int k, int sum, int mainIndex,vector<bool>& used){

if(k==1)
    return true;

    if(sum==target)
        return solve(A,target,k-1,0,0,used);

    for(int i = mainIndex; i<A.size();i++){

        if(!used[i]){
            used[i] = true;
            bool furtherSolution = solve(A,target,k,sum+A[i],i+1,used);
            if(furtherSolution)
                return true;
            else
                used[i] = false; //Backtrack
        }
    }
return false;
  
}

 bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = 0;
        for(auto elem : nums)
            totalSum+=elem;
        
        if(k==0 || totalSum%k!=0)
            return false;    
        
        int target = totalSum/k;
        vector<bool> used(nums.size(),false);

        return solve(nums,target,k,0,0, used);

    }

int main(){

vector<int> nums = {4,3,2,3,5,2,1};
int k = 4;

cout<<canPartitionKSubsets(nums,k);
    return 0;
}