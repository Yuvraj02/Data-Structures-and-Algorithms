#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> a;
    	
    	for(int i = 0; i<n;i++)
    	    a.push_back({arr[i],dep[i]});
    	 
    	 sort(a.begin(),a.end());   
    	//Build a minHeap, so that the train can be replaced with a new train
    	 
    	priority_queue<int,vector<int>,greater<int>> minHeap;
    	
    	minHeap.push(a[0].second);
    	
    	int cnt = 1;
    	for(int i = 1; i<a.size();i++){
    	   
    	   if(minHeap.top() >= a[i].first)
    	        cnt++;
    	   else
    	        minHeap.pop(); //Depart the train from the platform
    	   minHeap.push(a[i].second);
    	}
    	return cnt;
    }
};