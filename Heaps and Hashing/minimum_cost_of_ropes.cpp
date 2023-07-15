 #include <iostream>
 #include <queue>
 
 using namespace std;
 
 long long minCost(long long arr[], long long n) {
        // Your code here
        
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        
        for(long long i = 0;i<n;i++){
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        
        while(pq.size()>1){
            //Take two top elements, add them and push back
            long long a = pq.top();
            pq.pop();
            
            long long b = pq.top();
            pq.pop();
            
            cost+=a+b;
            
            pq.push(a+b);
        }
        
        return cost;
        
    }