#include <iostream>
#include <vector>
using namespace std;

long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int count=0;
        bool notPossible = false;
        for(int l = 0;l<nums1.size();l++){
          //  cout<<"YE";
            if(nums1[l]==nums2[l])
                    continue;
            
            int i=0,j=0;
            //Find smaller element in nums1
            while(nums1[i]>=nums2[i] && i<nums1.size()){
                cout<<nums1[i]<<" "<<nums2[i]<<endl;
                i++;
                
            } 
            //Find bigger element in nums2
            while(nums1[j]<=nums2[j] && j<nums1.size()){
                break;
                j++;
            }
                  

            if((i<nums1.size() && j==nums1.size()) || (j<nums1.size() && i==nums1.size())){
                 //cout<<"No";
                 //cout<<i<<" "<<j;
                notPossible = true;
            }
            
           // Increment i
            while(nums1[i]<nums2[i] && i<nums1.size()){
                //cout<<"Yes";
                nums1[i]+=k;
                
                if(nums1[i]>nums2[i]){
                    //cout<<"No";
                    notPossible = true;
                }
                    
                
            }
          //  Decrement j
            while(nums1[j]>nums2[j] && j<nums1.size()){
                nums1[j]-=k;
                
                if(nums1[j]<nums2[j]){
                    //cout<<"NO";
                    notPossible = true;

                }
                        
            }

            count++;
            
            if(notPossible){
                return -1;
            }
            
        }
        return count;
        
    }

    int main(){

        vector<int> A = {4,3,1,4};
        vector<int> B = {1,3,7,1};
        int k = 3;
        cout<<minOperations(A,B,k);
    }