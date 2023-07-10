#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        stack<long long> s;
        s.push(LLONG_MAX);
        vector<long long> ans(n,0);
        for(int i = n-1; i>=0;i--){
            while(!s.empty() && arr[i] >= s.top())
                s.pop();
                
            ans[i] = s.top() == LLONG_MAX ? -1 : s.top();
            s.push(arr[i]);
        }
        return ans;
}

int main(){
    vector<long long> A = {3,5,6,2,1};
    for(auto i : nextLargerElement(A,A.size()))
        cout<<i<<" ";
    return 0;
}