#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> findSubsequence(vector<int> &arr){

    unordered_map<int,int>umap;
    int n=arr.size();
    vector<int> duplicates;
    for(int i=0;i<n;i++){
        umap[arr[i]]++;
        if(umap[arr[i]]>1) duplicates.push_back(arr[i]);
    }
    sort(duplicates.begin(),duplicates.end());
    int i=duplicates.size()-1;
    int j=n-1;
    vector<int>result(duplicates.size(),0);
    while(i>=0 && j>=0){
        if(arr[j]==duplicates[i]){
            result[i]=1;
            i--;
            j--;
        }
        else j--;
    }
    // cout<<count(result.begin(),result.end(),1)<<endl;
    if(count(result.begin(),result.end(),1)==result.size()) return duplicates;
    return {-1};
}

int main(){
    vector<int> arr = {2,1,3,1,4,1,3}; 
   for(auto i : findSubsequence(arr))
    cout<<i<<" ";

    return 0;
}
