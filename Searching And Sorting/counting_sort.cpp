#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> A = {-1 ,2 ,3 ,-4 ,-5};
    
    int maxVal = *max_element(A.begin(),A.end());
    int minVal = *min_element(A.begin(),A.end());
    int range = maxVal-minVal+1;

    vector<int> count(range,0), output(A.size(),0);

    //store count of each value
    for (int i = 0; i < A.size(); i++)
    {
        count[A[i]-minVal]++;
    }
    
    //Add up all values
    for (int i = 1; i < count.size(); i++)
    {
        count[i]+=count[i-1];
    }
    
    //store in output array;
    for (int i = A.size()-1; i >= 0; i--)
    {
        output[count[A[i]-minVal]-1] = A[i];
        count[A[i]-minVal]--;
    }
    
    for(auto i : output){
        cout<<i<<" ";
    }
    
    return 0;
}