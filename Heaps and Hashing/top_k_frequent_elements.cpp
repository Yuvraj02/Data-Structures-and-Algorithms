 #include <iostream>
 #include <vector>
 #include <queue>
 #include <map>
 using namespace std;

 vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;

        for(int i = 0; i<nums.size();i++)
            freq[nums[i]]++;

        //Create a Min Heap to store elements
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        
        auto it = freq.begin();
        int i = 0;
        
        //Store first k frequencies to the min Heap
        while(i<k && it!=freq.end()){
            minHeap.push({it->second,it->first});
            i++;
            it++;
        }

        /*  Now add the remaining frequencies and check if the top of heap is less,
            Means if the frequency of top element is less then pop it and store
            more frequent element
        */
        while(it!=freq.end()){
            if(it->second > minHeap.top().first){
                minHeap.pop();
                minHeap.push({it->second,it->first});
            }

            it++;
        }
        //Store the answer from the heap, as the heap will be of k size only
        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }

     int main(){
        vector<int> nums = {1,1,1,2,2,3};
        int k = 2;
        for(auto i : topKFrequent(nums,k))
            cout<<i<<" ";

        return 0;
     }