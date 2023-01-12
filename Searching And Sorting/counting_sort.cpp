#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> A = {1,4,1,2,7,5,2};
    int minVal = *min_element(A.begin(),A.end());
    int maxVal = *max_element(A.begin(),A.end());

    int range;
    if(minVal<0)
    range = maxVal-minVal+1;
    else
    range = maxVal+2;

    vector<int> count(range), output;

    for (int i = 0; i < A.size(); i++)
    {
        if(minVal<0)
            count[A[i]-minVal]++;
        else
            count[A[i]]++;
    }

    int i=0;
    while (i<count.size())
    {
        if(count[i]!=0){
            if(minVal<0){
                output.push_back(minVal+i);
            }else{
                output.push_back(i);
            }
            count[i]--;
        }else{
            i++;
        }
    }
    
    for(auto i : output){
        cout<<i<<" ";
    }
    
    return 0;
}