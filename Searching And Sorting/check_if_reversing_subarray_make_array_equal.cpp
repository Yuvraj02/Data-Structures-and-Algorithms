#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& A, int left, int right){

    int i = left,j=right;
   // cout<<left<<" "<<right<<endl;
    while(i<=j){
        swap(A[i],A[j]);
        i++;
        j--;
    }
}

int main(){

    vector<int> A = {1,2,5,4,3};

    int left=-1,right=-1;

    for (int i = 0; i < A.size()-1; i++)
    {
        if(A[i]>A[i+1]){
            if(left==-1){
                left=i;
            }
            right=i+1;
        }
    }

    cout<<left<<" "<<right<<endl;
    
    if(left!=-1){
        reverse(A,left,right);
    }
    
    bool isPossible = true;    
    for(int i = 0; i< A.size()-1;i++){
        if(A[i]>A[i+1]){
            isPossible = false;
            break;
        }
    }

    if(isPossible)
        cout<<"YES";
    else
    cout<<"NO";

    return 0;
}