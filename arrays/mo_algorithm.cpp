#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int squareRootN;

class Query{
    public:
        int L,R;

    Query(int L,int R){
        this->L = L;
        this->R = R;
    }
};

bool compare(Query q1, Query q2){
    if(q1.L/squareRootN == q2.L/squareRootN){
        return q1.R>q2.R;
    }
    return q1.L/squareRootN < q2.L/squareRootN;
}

int main(){

    vector<int> A = {1,1,2,1,3,4,5,2,8,};
    vector<Query> queries = {Query(0,4),Query(1,3),Query(2,4)};
    
    squareRootN = (int) sqrt(A.size());

    sort(queries.begin(),queries.end(),compare);

    // for (int i = 0; i < queries.size(); i++)
    // {
    //     cout<<queries[i].L<<","<<queries[i].R<<endl;
    // }
    vector<int> ans;
    int curr_l=0,curr_r=-1,l,r,curr_ans=0;

    for (int i = 0; i < queries.size(); i++)
    {
        l = queries[i].L;
        r = queries[i].R;
        l--;r--;

        while (curr_r<r)
        {  
            curr_r++;
            curr_ans +=  A[curr_r];
        }

        while (curr_r>r)
        {
            curr_ans -= A[curr_r];
            curr_r--;  
        }
        
        while (curr_l<l)
        {
            curr_ans -= A[curr_l];
            curr_l++;
        }
        
        while (curr_l>l)
        {
            curr_l--;
            curr_ans += A[curr_l];
        }
        
    ans.push_back(curr_ans);
    }
    
    for (auto i : ans)
    {
        cout<<i<<" ";
    }
    

    return 0;
}