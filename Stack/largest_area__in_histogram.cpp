#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> getPrevSmallerElems(vector<int> &a){

    stack<int> s;
    s.push(-1);
    vector<int> prev(a.size());
    for (int i = 0; i < a.size(); i++)
    {   
        while(s.top()!=-1 && (a[s.top()] >= a[i])) s.pop();

        prev[i] = s.top();
        s.push(i);
    }
    return prev;    
}

vector<int> getNextSmallerElems(vector<int> a){
    stack<int> s;
    s.push(-1);

    vector<int> next(a.size());
    for(int i=a.size()-1; i>=0; i--){

        while(s.top()!= -1 && a[s.top()] >= a[i]) s.pop();

        next[i] = s.top();
        s.push(i);
    }

    return next;
}

int main(){

    vector<int> a = {2,4};

    vector<int> prevSmallerElem = getPrevSmallerElems(a);
    vector<int> nextSmallerElem = getNextSmallerElems(a);

    int length, breadth, maxArea = INT32_MIN;
    int newArea = INT32_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        length = a[i];
        if(nextSmallerElem[i]==-1) nextSmallerElem[i] = a.size();
        breadth = nextSmallerElem[i]-prevSmallerElem[i]-1;

        newArea = length*breadth;
        maxArea = max(maxArea, newArea);
    }
    cout<<maxArea;

    return 0;
}