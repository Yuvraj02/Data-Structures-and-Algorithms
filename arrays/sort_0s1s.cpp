#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> a = {1,1,0,0,0,0};

    int i=0,j=a.size()-1;

    while (i<j)
    {
        if(a[i]==0){
            i++;
        }else if(a[j]==1){
            j--;
        }else{
            swap(a[i],a[j]);
            i++;
            j--;
        } 
    }
    
for (auto i : a)
{
    cout<<i<<" ";
}


    return 0;
}