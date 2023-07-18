/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i])
where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when 
only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/


#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

static bool compare(pair<int,int> a, pair<int,int> b){
        
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> intervals;
        
        for(int i = 0; i<n;i++){
            intervals.push_back({start[i],end[i]});
        }
        
        sort(intervals.begin(),intervals.end(),compare);
        
        // for(auto i:intervals){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        int count = 1;
        int l=0;
        for(int r = 1; r<intervals.size();r++){
                
                if(intervals[r].first > intervals[l].second){
                    count++;
                    l=r;
                }
        }
        
        
        return count;

    }