#include <iostream>
#include <vector>

using namespace std;

void subsets(vector<int> arr, vector<int> output,int i,vector<vector<int>> &finalVec){

if(i>=arr.size()){
    finalVec.push_back(output);
    return;
}
    
    //Excluding
    subsets(arr,output,i+1,finalVec);
    //Include
    int element = arr[i];
    output.push_back(element);
    subsets(arr,output,i+1,finalVec);

}

int main(){

    vector<int> arr = {1,2,3};
    vector<int> output;
    vector<vector<int>> A;
    subsets(arr,output,0,A);

    for (int i = 0; i < A.size(); i++)
    {
        for(int j = 0;j<A[i].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}