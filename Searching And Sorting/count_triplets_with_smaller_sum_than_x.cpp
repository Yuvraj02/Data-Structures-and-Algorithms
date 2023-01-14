#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> A = {1,2,3,4,6};
    int sum =10;
    sort(A.begin(),A.end());

    int count=0;
    for (int i = 0; i < A.size(); i++)
    {

        if(i!=0 && A[i]==A[i-1] )
            continue;

        int left = i+1,right=A.size()-1;

        while (left<right)
        {
            if(A[i]+A[left]+A[right]<sum){
                count+= (right-(left+1))+1;
                left++;
                right = A.size()-1;              
            }else{
                right--;
            }
            
        }
        
    }
    
    cout<<count;


    return 0;
}