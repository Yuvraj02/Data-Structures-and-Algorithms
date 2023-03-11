#include <iostream>
#include <vector>
#include <deque>

using namespace std;

long long sumOfMaxAndMin(vector<int> &A, int n, int k) {

	deque<int> maxi,mini;
	int sum = 0;
	for(int i=0;i<k;i++){
		
		while(!maxi.empty() && A[maxi.back()] >= A[i])
			maxi.pop_back();
		
		while(!mini.empty() && A[mini.back()] <= A[i])
			mini.pop_back();

			maxi.push_back(i);
			mini.push_back(i);
	}

	for(int i = k; i<n; i++){
		sum += A[maxi.front()] + A[mini.front()];

		//Remove from window
		while(!maxi.empty() && maxi.front() <= i-k)
			maxi.pop_front();
			
		while(!mini.empty() && mini.front() <= i-k)
			mini.pop_front();

		while(!maxi.empty() && A[maxi.back()] >= A[i])
			maxi.pop_back();
		
		while(!mini.empty() && A[mini.back()] <= A[i])
			mini.pop_back();

			maxi.push_back(i);
			mini.push_back(i);
	}

	sum += A[maxi.front()] + A[mini.front()];

	return sum;

}


int main(){

    vector<int> A = {2, 5, -1, 7, -3, -1, -2} ;
    int k = 4;
    cout<<sumOfMaxAndMin(A,A.size(),k)<<endl;
    
    return 0;
}