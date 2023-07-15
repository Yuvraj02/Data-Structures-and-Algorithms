#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.

	priority_queue<int,vector<int>, greater<int>> pq;

	for(int i = 0; i<arr.size();i++){
		int sum = 0;
		for(int j = i; j<arr.size();j++){

			sum+=arr[j];

			if(pq.size() < k){
				pq.push(sum);
			}else{
				if(sum > pq.top()){
					pq.pop();
					pq.push(sum);
				}
			}
		}
	}

	return pq.top();

}