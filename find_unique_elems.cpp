#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> A = {6,2,5,2,2,6,6};

    int count=0,k=3;


    //----------Brute Force Approach

    // for (int i = 0; i < A.size(); i++)
    // {
    //     count=0;
    //     for (int j = 0; j < A.size(); j++)
    //     {
    //         if(A[i]==A[j])
    //         count++;
    //     }

    //     if(count%k!=0 ){
    //         cout<<A[i]<<endl;
    //         break;
    //     }   
    // }


//------------ Optimized 
    sort(A.begin(),A.end());

    for (int i = 0; i < A.size(); i++)
    {
        count=1;

            if(A[i]==A[i+1])
                count++;
            else if(count%k!=0)
                return A[i];

    }

//----------- Can be more optimized using maps

    for (auto i : A)
    {
        cout<<i<<endl;
    }
    

    return 0;
}