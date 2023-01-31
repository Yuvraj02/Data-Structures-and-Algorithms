#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& arr, int mainIndex, int &difference,vector<int> &A,vector<int> &B,int sumOfSet1, int sumOfSet2){

    if(mainIndex==arr.size()){
        difference = min(difference, abs(sumOfSet1-sumOfSet2));
        return ;
    }

    //Solve for set 1
    if(A.size() < (arr.size()+1)/2){
    A.push_back(arr[mainIndex]);
    solve(arr,mainIndex+1,difference,A,B, sumOfSet1+arr[mainIndex],sumOfSet2);
    A.pop_back();
    }
    //Solve for set 2
    if(B.size() < (arr.size()+1)/2){
    B.push_back(arr[mainIndex]);
    solve(arr,mainIndex+1, difference,A,B, sumOfSet1,sumOfSet2+arr[mainIndex]);
    B.pop_back();
    }

}


int tugOfWar(vector<int> &arr, int n)
{
    int sides = 2;

    vector<bool> used (n,false);
    vector<int> A,B;
    int difference = INT32_MAX;
    solve(arr,0,difference,A,B,0,0);
    // int target;
    // if (total%2!=0)
    // {
    //     target = (total/2);
    // }
    return difference;
}

int main(){

    vector<int> A = {4,2,1};

    cout<<tugOfWar(A,A.size());

    return 0;
}