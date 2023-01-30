//This is a backtracking approach, it will solve the problem but will give a time limit exceeded error

#include <iostream>

using namespace std;

bool solve(int arr[], int N, int buckets, int target, int sum, bool used[], int mainIndex){

    if(buckets==1){
        return true;
    }

    if(sum == target)
        return solve(arr,N,buckets-1,target,0,used,0);
    
    for (int i = mainIndex; i < N; i++)
    {
        if(!used[i]){
            used[i] = true;
            bool furtherSolution = solve(arr,N,buckets,target,sum+arr[i],used,i+1);
            if(furtherSolution)
                return true;
            else
                used[i]=false;
        }
    }
return false;
}

int equalPartition(int N, int arr[]) {

    int buckets = 2;

    int total = 0;
    for(int i=0;i<N;i++){
        total+=arr[i];
    }

    if(total%buckets!=0)
        return false;

    int target = total/buckets;

    bool used[N] = {false};

    return solve(arr,N,buckets,target,0,used,0);

}

int main(){

    int arr[] = {1,5,11,5};
    int N = 4;

    if(equalPartition(4,arr))
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}