#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> A = {39,11,100,99,65,19,13};

    sort(A.begin(),A.end(),greater<int>());

    int left = 0,right=1;
    int time=0;
    while (right<A.size())
    {   
            if(A[left]!=0 && A[right]!=0){
                A[left]--;
                A[right]--;
                time++;
            }else if(A[right]==0){
                right++;
            }else if(A[left]==0){
                left = right;
                right++;
            }

    }
    
    cout<<time;
    


    return 0;
}