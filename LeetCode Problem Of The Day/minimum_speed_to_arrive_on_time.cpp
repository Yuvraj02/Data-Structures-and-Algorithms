#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


bool canTravel(vector<int> &dist, double hour, int speed){
        
        double timeTaken = 0;

        for(int i = 0; i<dist.size();i++){
            double currTime = dist[i]*1.0/speed;
            
            if(i<dist.size()-1)
                timeTaken += ceil(currTime);
            else
                timeTaken += currTime;

            if(timeTaken > hour)
                return false;
        }
    return true;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int end = 1e7;

        int start = 1;
        int mid = (start + end)/2;
        int ans = -1;

        while(start<=end){
            
            if(canTravel(dist,hour,mid)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
            mid = (start+end)/2;
        }
    return ans;
    }

    int main(){
        vector<int> dist = {1,3,2};
        double hour = 2.7;

        cout<<minSpeedOnTime(dist,hour);

        return 0;
    }