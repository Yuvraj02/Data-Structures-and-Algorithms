#include <iostream>

using namespace std;

int findSum(int A[], int N){

    int maxNum=INT32_MIN,minNum=INT32_MAX;

    for (int i = 0; i < N; i++)
    {
            maxNum = max(maxNum,A[i]);
            minNum = min(minNum,A[i]);
    }
    
    return maxNum+minNum;

}

int main(){
    int A[] = {-2,1,-4,5,3};
    int n = sizeof(A)/sizeof(int);

   cout<<findSum(A,n);

    return 0;
}