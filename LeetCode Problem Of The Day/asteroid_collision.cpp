#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>

using namespace std;

vector<int> asteroidCollision(vector<int>& arr) {
        
        stack<int> s;

        for(int i = 0; i<arr.size();i++){

            if(!s.empty() && (s.top() > 0 && arr[i] < 0)){
                while(!s.empty() && s.top() > 0 && s.top() < abs(arr[i]) ){
                    s.pop();
                }
                if(!s.empty()){
                    if(s.top() > 0 && s.top() == abs(arr[i])){
                        s.pop();
                    }else if(s.top() < 0){
                        s.push(arr[i]);
                    }
                }else{
                    s.push(arr[i]);
                }
            }else{
                s.push(arr[i]);
            }
        }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;

    }