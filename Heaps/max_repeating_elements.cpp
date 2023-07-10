#include <iostream>
#include <vector>

using namespace std;
int maxRepeating(int *arr, int n, int k) {
	    // code here
	    vector<int> count(k,0);
	    
	    for(int i = 0; i<n;i++)
	        count[arr[i]]++;
	        
	   int max_freq = 0;
	   int max_elem = 0;
	   
	   for(int i = 0; i<k;i++){
	       if(count[i] > max_freq){
	           max_freq = count[i];
	           max_elem = i;
	           
	       }
	   }
	   return max_elem;
	}

int main(){

    int arr[] = {2,2,1,2};
    int k = 3;
    cout<<maxRepeating(arr,4,k);
    return 0;
}