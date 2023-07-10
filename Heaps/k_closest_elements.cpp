#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr,int x){
        
        int start = 0;
        int end = arr.size()-1;
        
        int mid = (start + end)/2;
        
        while(start<end){
            
            if(arr[mid]<=x && arr[mid+1]>x)
                return mid;
            else if(arr[mid] < x){
                //Go to right half
                start = mid+1;
            }else{
                end = mid-1;
            }
            mid = (start + end)/2;
        }
        
        // return -1;
    }
  
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        int left = binarySearch(arr,x);
        
        int right = left+1;
        
        if(arr[left] == x)
            left--;
            
        int count = 0;
        vector<int> ans;
        
        while(left>=0 && right<n && count<k){
          
            if((x-arr[left] < arr[right]-x)){
                ans.push_back(arr[left]);
                left--;
                 
            }else{
                ans.push_back(arr[right]);
                right++;
            }
            count++;
        }
        
        //If only left side exists
        while(left>=0 && count<k){
            ans.push_back(arr[left]);
            left--;
            count++;
        }
        
        //If only right side exists
        while(right < n && count<k){
            ans.push_back(arr[right]);
            right++;
            count++;
        }
        
        return ans;
    }

int main(){

   int N = 13;
   vector<int> arr = {12, 16, 22, 30, 35, 39, 42,45, 48, 50, 53, 55, 56};
   int K = 4, X = 35;
   for(auto i : printKClosest(arr,N,K,X))
    cout<<i<<" ";
 return 0;   
}