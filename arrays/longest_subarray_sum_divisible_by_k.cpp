#include <iostream>
#include <vector>
#include <unordered_map>

//A map of key-value pair where key-> remainder, value->index
using namespace std;

int main(){

    vector<int> A = {-2, 2, -5, 12, -11, -1, 7};
    int k = 3;
    unordered_map<int,int> m;
    int sum=0,remainder=0,maxLength = INT32_MIN;
    
    for (int i = 0; i < A.size(); i++)
    {
            sum+=A[i];

            remainder = sum%k;
            if(remainder<0)
                remainder = remainder+k;

            auto it = m.find(remainder);
            //If remainder is found
            if(it!=m.end()){
                //Subtract the current index - the previous value index
                maxLength = max(maxLength, i-(it->second));
            }else{
                m.insert(make_pair(remainder,i));
            }
    }
    
    cout<<maxLength;

    return 0;
}