#include <iostream>
#include <vector>

using namespace std;

long long findTheArrayConcVal(vector<int>& nums) {
        
        long long output = 0;

        int i = 0, j = nums.size()-1;

        while (i<=j)
        {
            if(i==j){
                output+=nums[i];
            }else{
            string concat = to_string(nums[i]) + to_string(nums[j]);
            output+= stoi(concat);
            }
            i++;
            j--;
        }
        
return output;
}

int main(){

    vector<int> A = {};
    
    cout<<findTheArrayConcVal(A);

    return 0;
}