#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 
 vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        
        vector<int> output(n);
        
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        for(int i = 0 ; i < n;i++){
            
            if(minHeap.size()<k){
                minHeap.push(arr[i]);
            }else{
                if(minHeap.top() < arr[i]){
                    minHeap.pop();
                    minHeap.push(arr[i]);
                }
            }
            
            if(minHeap.size()<k){
                output[i] = -1;
            }else{
                output[i] = minHeap.top();
            }
            
        }
        
        return output;
    }

    int main(){
        int k = 4;
        const int n = 6;
        int arr[n] = {1, 2, 3, 4, 5, 6};
        for(auto i : kthLargest(k,arr,n))
            cout<<i<<" ";

        return 0;
    }