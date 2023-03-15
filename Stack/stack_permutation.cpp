#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        int i = 0,j=0;
        stack<int> s;
        
        for(int i = 0;i < N; i++){
            s.push(A[i]);
            while(!s.empty() && B[j]==s.top()){
                s.pop();
                j++;
            }
        }
        
        if(s.empty() && j>=B.size())
            return true;
        else
            return false;   
    }



int main(){

    int N = 3;
    vector<int> A = {1,2,3};
    vector<int> B = {2,1,3};

    cout<<isStackPermutation(N,A,B);
    return 0;
}