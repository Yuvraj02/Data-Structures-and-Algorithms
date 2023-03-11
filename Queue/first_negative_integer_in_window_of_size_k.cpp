#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//Optimized Approach , Time : O(N), Space O(1)
vector<long long> printFirst(vector<int> A, int N, int K){
    
    int firstNegativeIndex = 0;
    vector<long long> ans;
    
    for(int i = K-1; i<N;i++){
        
        //Skip the Positives nums or nums out of window
        //(firstNegativeIndex <= i-k) means, if the last negative element is out of the window
        while(firstNegativeIndex < i && ((firstNegativeIndex <= i-K) || A[firstNegativeIndex] >=0))
            firstNegativeIndex++;
            
            if(A[firstNegativeIndex] <= 0){
                ans.push_back(A[firstNegativeIndex]);
            }else{
                ans.push_back(0);
            }
    }

    return ans;
}


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