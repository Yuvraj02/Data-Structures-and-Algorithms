#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){

    vector<int> arr = {2,4,3,1};
    int n = arr.size();
    vector<int> ans(n);

    stack<int> s;
    s.push(-1);

    for (int i = n-1; i >= 0; i--)
    {
        int curr = arr[i];
        while(s.top() >= curr) s.pop();

        ans[i] = s.top();
        s.push(curr);
    }

    for(auto i : ans){
        cout<<i<<" ";
    }
    
    return 0;
}