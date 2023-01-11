#include <iostream>
#include <vector>
using namespace std;

bool isPossibleMinTime(vector<int> A, int dishes, int givenTime){

    int dishesCount = 0,time=0;

    for (int i = 0; i < A.size(); i++)
    {
        int j=2;
        time=A[i];
        while (time<=givenTime)
        {
            time=time + (A[i]*j);
            j++;
            dishesCount++;
        }

        if(dishesCount>=dishes){
            return true;
        }
    }
    return false;
}

int minTime(vector<int> A, int dishes){

    int start = 0,maxNum=INT32_MIN;

    for (int i = 0; i < A.size(); i++)
    {
        maxNum=max(A[i],maxNum);
    }   

    int end = maxNum;
    for (int i = 2; i <= dishes; i++)
    {
        end+=maxNum*i;
    }

    int mid = start + (end-start)/2;
    int ans = -1;
    while (start<=end)
    {
        if(isPossibleMinTime(A,dishes,mid)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
        mid = start + (end-start)/2;
    }
    
    return ans;
}

int main(){

    vector<int> A ={1,2,3,4};
    int m = 11;
    cout<<minTime(A,m);
    return 0;
}