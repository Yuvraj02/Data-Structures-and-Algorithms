#include <iostream>
#include <vector>

using namespace std;

int sqrt(int x){

    int start =0,end=x,mid=start + (end-start)/2;
    int ans = -1;
    while (start<=end)
    {
        if(mid*mid==x){
            return mid;
        }else if(mid*mid<x){
            ans = mid;
            start=mid+1;
        }else{
            end=mid-1;
        }

        mid = start + (end-start)/2;
    }
    return ans;

}


int main(){

    cout<<sqrt(8)<<endl;

    return 0;
}