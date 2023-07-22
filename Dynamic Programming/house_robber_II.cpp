#include <iostream>
#include <vector>

using namespace std;

 int solve(int i, vector<int> &nums){
        if(i>=nums.size())
            return 0;

        int include = nums[i] + solve(i+2, nums);

        int exclude = solve(i+1,nums);

        return max(include,exclude);
    }

    int solveMem(vector<int> &a,vector<int> &b){

        int solveA = solve(0,a);
        int solveB = solve(0,b);

        return max(solveA,solveB);
    }

    int solveTab(vector<int> &a, vector<int> &b){
        
        int n1 = a.size();
        int n2 = b.size();
        vector<int> dp1 (n1+2, 0);
        vector<int> dp2 (n2+2, 0);

        //For vector a 
        for(int i = n1-1; i >=0 ;i--){
        
        int include = a[i] + dp1[i+2];

        int exclude = dp1[i+1];

        dp1[i]= max (include,exclude);
        }

        for(int i = n2-1; i >=0 ;i--){
        
        int include = b[i] + dp2[i+2];

        int exclude = dp2[i+1];

        dp2[i]= max (include,exclude);
        }

        return max(dp1[0],dp2[0]);
    }

    int spaceOptim(vector<int> &a, vector<int> &b){

        int n = a.size();

        int curr_of_a=0;
        int next2_of_a=0;

        for(int i = n-1; i>=0; i--){

            int include = a[i] + next2_of_a;
            int exclude = curr_of_a;
            next2_of_a = curr_of_a;
            curr_of_a = max(include,exclude);
        }

        int curr_of_b=0;
        int next2_of_b=0;

        for(int i = n-1; i>=0; i--){

            int include = b[i] + next2_of_b;
            int exclude = curr_of_b;
            next2_of_b = curr_of_b;
            curr_of_b = max(include,exclude);
        }
        return max(curr_of_a,curr_of_b);
    }

    int rob(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];

        vector<int> a;  //Will have houses excluding last house
        vector<int> b; // Will have houses excluding first and including last house

        for(int i = 0; i<nums.size();i++){
                if(i==0){
                    a.push_back(nums[i]);
                }else if(i==nums.size()-1){
                    b.push_back(nums[i]);
                }else{
                    a.push_back(nums[i]);
                    b.push_back(nums[i]);
                }
        }
       // return solveMem(nums)
      // return solveTab(a,b);
        return spaceOptim(a,b);
    }

