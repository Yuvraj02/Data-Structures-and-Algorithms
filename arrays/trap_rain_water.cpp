#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> A = {0,2,0};
    
    int maxLeft = A[0];
    int maxRight = A[A.size()-1];
    int L=1,R=A.size()-2;
    int trappedWater=0;

    while (L<=R)
    {
        if(maxLeft<maxRight){
            if(A[L]<maxLeft){
                trappedWater+= maxLeft-A[L];
                
            }else{
                maxLeft=A[L];
            }
          L++;  
        }else{
            if(A[R]<maxRight){
                trappedWater+=maxRight-A[R];
                
            }else{
                maxRight = A[R];
            }
          R--;
        }
    }
    
    cout<<trappedWater;

//Auxiliary Arrays
    // vector<int> maxLeft,maxRight;
    // int maxLeftNum = INT32_MIN,maxRightNum=INT32_MIN;

    // //For left to right
    // for (int i = 0; i < A.size(); i++)
    // {
    //         if(i==0){
    //             maxLeft.push_back(0);
    //         }else{
    //             maxLeftNum = max(A[i-1],maxLeftNum);
    //             maxLeft.push_back(maxLeftNum);
    //         }
           
    // }
    
    // //For Right to left

    // for (int i = A.size()-2; i >= 0; i--)
    // {

    //     maxRightNum = max(maxRightNum,A[i+1]);
    //     maxRight.push_back(maxRightNum);

    //     if(i==0){
    //         maxRight.push_back(0);
    //     }
        
    // }
    
    // int minimumVal,trappedWater=0;
    // for (int i = 1; i < maxLeft.size()-1; i++)
    // {
    //     minimumVal = min(maxLeft[i],maxRight[i]) - A[i];
    //     trappedWater+=minimumVal;
    // }
    

    // cout<<trappedWater;
    // for (auto i : maxRight)
    // {
    //     cout<<i<<" ";
    // }
    

    return 0;
}