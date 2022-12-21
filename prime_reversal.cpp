#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin>>t;

    while (t--)
    {
        int n;
        string A,B;
        cin>>n>>A>>B;

        if(A==B){
            cout<<"YES"<<endl;
        }else{
            vector<int> nums;
            for (int i = 0; i < A.size(); i++)
            {
                if(A[i]!=B[i]){
                    nums.push_back(i);
                }   
            }

            int i=nums[0],j=nums[nums.size()-1];
            while (i<j)
            {
                swap(A[i],A[j]);
                i++;
                j--;
            }
            if(A==B){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}