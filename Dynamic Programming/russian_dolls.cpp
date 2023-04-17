#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(vector<int> a, vector<int> b){

    if(a[0]==b[0])
        return a[1]>b[1];
    
    return a[0]<b[0];
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
        
         sort(envelopes.begin(),envelopes.end(),comparator);


        vector<int> height;
        
        for(int i=0;i<envelopes.size();i++)
            height.push_back(envelopes[i][1]);
        
        vector<int> ans;
        ans.push_back(height[0]);

        for(int i=1;i<height.size();i++){
            if(height[i] > ans.back()){
                ans.push_back(height[i]);
            }else{
                int index = lower_bound(ans.begin(),ans.end(),height[i]) - ans.begin();
                ans[index] = height[i];
            }
        }
        return ans.size();
    }


int main(){

    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    cout<<maxEnvelopes(envelopes);
    return 0;
}