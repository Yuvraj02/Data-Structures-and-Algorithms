#include <iostream>
#include <vector>

using namespace std;

vector<long> findSum(vector<int> numbers, vector<vector<int>> queries) {

        vector<long> finalVec;
        
        for (int i = 0; i < queries.size(); i++)
        {
            int l=queries[i][0],r=queries[i][1],x=queries[i][2];
            int flag = 0;
            int sum = 0;
           // cout<<l<<" "<< r<<" "<<x<<" ";
            for (int j = (l-1); j <= (r-1); j++)
            {
                //cout<<j<<" ";
                sum += numbers[j];
                if(numbers[j]==0 && flag==0){
                   
                    sum += x;
                    flag=1;
                }

            }

            finalVec.push_back(sum);

        }
        
    return finalVec;        
   
}

int main(){

       vector<int> nums = {-5,0,2};        
       vector<vector<int>> q = {{2,2,10},
                                {1,2,10}};

        for(auto i : findSum(nums,q)){
            cout<<i<<" ";
        }
    
}
