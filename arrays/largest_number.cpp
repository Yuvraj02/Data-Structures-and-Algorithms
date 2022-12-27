#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


bool compare(int a, int b){
     
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);

return ab>ba;
}
   

int main(){

vector<int> nums = {10,2,9,39,17};

sort(nums.begin(),nums.end(),compare);

string a = "";

for (int i = 0; i < nums.size(); i++)
{
    a+=to_string(nums[i]);
}

cout<<a;

}