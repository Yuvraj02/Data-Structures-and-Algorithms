 #include <iostream>
 #include <vector>
 #include <queue>

 using namespace std;

 vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> maxOfSubs;
        
        priority_queue<pair<int,int>> maxHeap;
        
        for(int i = 0; i<k;i++){
            maxHeap.push({arr[i],i});
        }
        
        maxOfSubs.push_back(arr[maxHeap.top().second]);
       
        for(int i = k; i<n;i++){
            while(!maxHeap.empty() && maxHeap.top().second <= i-k)
                maxHeap.pop();
                
             maxHeap.push({arr[i],i});
             maxOfSubs.push_back(arr[maxHeap.top().second]);
        }
       
        return maxOfSubs;
    }

int main(){

    vector<int> arr = { 1 ,2, 3, 1,4,5 ,2 ,3, 6};
    int k =3;
    int n = 9;
    
    for(auto i:max_of_subarrays(arr,n,k))
        cout<<i<<" ";
    return 0;
}