#include <iostream>
#include <vector>
#include <queue>

using namespace std;

    
    
vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	//Use min heap to get k large elements     
	priority_queue<int,vector<int>, greater<int>> minHeap;
	    
	for(int i = 0; i<k;i++){
	    minHeap.push(arr[i]);
	}
	    
	    //Now from k to n elements
	    for(int i = k; i<n;i++){
	        if(minHeap.top() < arr[i]){
	            minHeap.pop();
	            minHeap.push(arr[i]);
	        }
	    }
	    
	    vector<int> ans;
	    
	    while(!minHeap.empty()){
	       
	       ans.push_back(minHeap.top());
	       minHeap.pop();
	        
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}

int main(){

        return 0;
}