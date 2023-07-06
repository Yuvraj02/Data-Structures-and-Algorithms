#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        stack<long long> s;
        
        s.push(LLONG_MAX);
        
        vector<long long> nextGreater(n);
        
        for(int i = arr.size()-1; i>=0 ;i--){
                
                //The condition is (greater than or equal to)
            while(!s.empty() && s.top() <= arr[i])
                s.pop();
            
            if(s.top()==LLONG_MAX)
                nextGreater[i] = -1;
            else
                nextGreater[i] = s.top();
            
            s.push(arr[i]);
        }
        
        return nextGreater;
}

int main(){
    vector<long long> A = {3,5,6,2,1};
    for(auto i : nextLargerElement(A,A.size()))
        cout<<i<<" ";
    return 0;
}