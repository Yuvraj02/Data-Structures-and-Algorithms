#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define N 4
#define M 4


vector<int> nextSmallerElement(int arr[], int n){

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){

        while(s.top()!=-1 && arr[s.top()] >= arr[i]) s.pop();

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> prevSmallerElement(int arr[], int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0; i<n;i++){

        while(s.top()!=-1 && arr[s.top()] >= arr[i]) s.pop();

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int getMaxArea(int arr[],int n){

    vector<int> next = nextSmallerElement(arr,n);
    vector<int> prev = prevSmallerElement(arr,n);

    int length, breadth, newArea = INT32_MIN, maxArea = INT32_MIN;

    for(int i=0;i<n;i++){
        length = arr[i];
        if(next[i]==-1) next[i] = n;
        breadth = next[i]-prev[i]-1;

        newArea = length*breadth;
        maxArea = max(maxArea,newArea);
    }
    return maxArea;
}

int maxArea(int matrix[N][M], int n, int m) {

    //Step 1 : Compute largest area of first row
    int maxArea=INT32_MIN;

    maxArea = max(maxArea, getMaxArea(matrix[0],m));

    //Step 2 : Add all previous rows and compute the area
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(matrix[i][j]!=0)
                matrix[i][j] += matrix[i-1][j];
        }
        maxArea = max(maxArea, getMaxArea(matrix[i],m));
    }

    return maxArea;
}

int main(){
    
    int n = 4, m = 4;
    int matrix[N][M] = {{0,1,1,0},
                        {1,1,1,1},
                        {1,1,1,1},
                        {1,1,0,0}};
    cout<<maxArea(matrix,n,m);

    return 0;
}