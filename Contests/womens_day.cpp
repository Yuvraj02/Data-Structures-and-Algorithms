#include <iostream>
#include <vector>

using namespace std;


int solve(int n, vector<int> &A,int window){

    if(n==0){
        return window;
    }
        

    int num1 = A[n];
    int num2 = A[n-1];
    int option1=0,option2=0;
    if(A[n-1] > 0 && A[n] > 0){

        A[n-1] = num1%num2;        
        option1 = 1 + solve(n-1,A,window-1);

        A[n-1] = num2%num1;
        option2 = 1 + solve(n-1,A,window-1);
    } 

    return max(option1,option2);

}

int getMinLength(vector<int> A){

    int n = A.size();
    int len = n-solve(A.size()-1,A,A.size());
    if(len)
        return len-1;
    else
        return 1;
}

int main(){

    vector<int> A = {29,36,57};
    vector<int> B = {25,18,3};
    vector<long> ans;
    
    for(int i=0;i<A.size();i++){

        long x = 0, long y= A[i];
        
        while(x<=y){
            if(x^y==B[i]){
                ans.push_back(2*x + 3*y);
                break;
            }
            x++;
            y--;
        }
    }

    for(auto i : ans)
        cout<<i<<" ";
}