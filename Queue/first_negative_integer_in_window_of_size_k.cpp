#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {

    queue<int> q;
    vector<long long> ans;
    for(int i = 0; i<K;i++){
        if(A[i]<0)
            q.push(i);
    }

        if(!q.empty()){
            ans.push_back(A[q.front()]);
        }else{
            ans.push_back(0);
        }

    for(int i = K ;i <N;i++){
            //Removal of elment;
            //If q.front is out of window
            if(!q.empty() && i - q.front() >= K){
                q.pop();
            }

            if(A[i]<0){
                q.push(i);
            }

            if(!q.empty()){
            ans.push_back(A[q.front()]);
        }else{
            ans.push_back(0);
        }
    }
    return ans;
}

int main(){

    long long int arr[] = {-8,2,3,-6,10};
    vector<long long> ans = printFirstNegativeInteger(arr,5,2);

    for(auto i:ans){
        cout<<i<<" ";
    }
}