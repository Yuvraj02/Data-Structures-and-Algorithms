#include <iostream>
#include <vector>

using namespace std;


// Iterative Method
    // for (int i = 0; i < a.size(); i++)
    // {
    //         for (int j = i+1; j < a.size(); j++)
    //         {
    //                 if(a[j]<a[i]){
    //                     swap(a[i],a[j]);
    //                 }
    //         }        
    // }

void selecSort(vector<int> &a,int j){

    if(j==a.size())
        return ;

    for (int i = j+1; i < a.size(); i++)
    {
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
    }
    selecSort(a,j+1);    
}


int main(){
    
    vector<int> a = {9,4,6,3,1,2,7};

    selecSort(a,0);
    
    for (auto i : a)
    {
        cout<<i<<" ";
    }
    
    return 0;
}