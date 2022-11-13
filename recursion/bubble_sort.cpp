#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &a,int n){

    if (n==0 || n==1)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if(a[i] > a[i+1])
            swap(a[i],a[i+1]);
    }
    
    bubbleSort(a,n-1);

}


int main(){

    vector<int> a = {5,2,3,1,4};

/* Iterative Method */
    // for (int i = 0; i < a.size(); i++)
    // {
    //         for (int j = 0; j < a.size()-i-1; j++)
    //         {
    //             if(a[j]>a[j+1]){
    //                 swap(a[j],a[j+1]);
    //             }
    //         }
    // }
        
        bubbleSort(a,a.size()-1);

    for (auto i : a)
    {
        cout<<i;
    }

    return 0;
}