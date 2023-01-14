#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> A = {1,5,9,10,15,20};
    vector<int> B = {2,3,8,13};

    // Using insertion Sort
    // Start from last index of 2nd array and 1st array

    for (int j = B.size()-1; j >=0 ; j--)
    {
        
        int lastElement = A[A.size()-1];

        int i = A.size()-2;

        while (i>=0 && B[j]<A[i])
        {
            A[i+1]=A[i];
            i--;
        }
        
        if(lastElement>B[j]){
            // A[i+1]=B[j];
            A[i+1]=B[j];
            B[j]=lastElement;
        }

    }
    cout<<"Array 1 : ";
    for (auto i : A)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Array 2: ";
    for (auto i : B)
    {
        cout<<i<<" ";
    }    
    return 0;
}    

    //Bruteforce
    // int i =0,j=0;

    // while (i<A.size() && j<B.size())
    // {
    //     if(B[j]<A[i]){
    //         swap(A[i],B[j]);
    //         sort(B.begin(),B.end());
    //     }
    //     i++;
    // }

     //Using 3 pointers O((N+M)*logn)

    // int i =0,j=0,k=A.size()-1;

    // while (i<=k && j<B.size())
    // {
        
    //     if(A[i]<B[j]){
    //         i++;
    //     }else{
    //         swap(B[j],A[k]);
    //         j++;
    //         k--;
    //     }
    // }
    // sort(A.begin(),A.end());
    // sort(B.begin(),B.end());
    
