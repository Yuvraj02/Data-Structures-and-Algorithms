#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


static bool compare(Job j1, Job j2){
        
        return j1.profit > j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,compare);
        
        int maxDeadline=INT32_MIN;
        for(int i = 0; i<n;i++){
            maxDeadline = max(maxDeadline,arr[i].dead);
        }
        
        vector<int> schedule(maxDeadline+1,-1);
        int profit = 0;
        int jobs=0;
        for(int i = 0; i<n;i++){
            int j = arr[i].dead;
            
            while(j>0 && schedule[j]!=-1) j--;
            if(j==0)
                continue;
                
            schedule[j] = arr[i].id;
            profit+= arr[i].profit;
            jobs++;
        }
        
        return {jobs,profit};
    } 