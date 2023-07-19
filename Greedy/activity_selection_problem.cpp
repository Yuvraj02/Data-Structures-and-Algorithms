 #include <iostream>
 #include <vector>
 #include <utility>
 #include <algorithm>

 using namespace std;   
  
   static bool compare(pair<int,int> &a, pair<int,int> &b){
            return a.second < b.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> intervals;
        
        for(int i = 0; i<n;i++){
            intervals.push_back({start[i],end[i]});
        }
        
        sort(intervals.begin(),intervals.end(),compare);
        
        int count = 1;
        
        int l = 0;
        
        for(int r = 1; r<n;r++){
            if(intervals[r].first > intervals[l].second){
                //cout<<"S";
                l=r;
                count++;
            }
        }
        return count;
    }