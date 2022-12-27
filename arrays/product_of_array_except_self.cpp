#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> A = {1,2,3,4};


    vector<int> finalVec;
    int product=1;

    //Most Optimal Solution : Time O(N), Space O(1)

    int prefix = 1,postfix=1;
    
    //Calculate for prefix
    for (int i = 0; i < A.size(); i++)
    {
        finalVec.push_back(prefix);
        prefix*=A[i];
    }

    //Calculate for postfix
    for (int i = A.size()-1; i >= 0; i--)
    {
        finalVec[i] *= postfix;
        postfix*=A[i];
    }
    
    
     for (auto i : finalVec)
    {
        cout<<i<<" ";
    }

    // //Optimized Approach : Time O(N), Space O(N)
    // vector<int> prefix(A.size());
    // vector<int> postfix(A.size());

    // //For prefix
    // for (int i = 0; i < A.size(); i++)
    // {
    //     product*=A[i];
    //    prefix[i] = product;
    // }
    
    // product=1;

    // //For postfix
    // for (int i = postfix.size()-1; i >=0; i--)
    // {
    //     product*=A[i];
    //     postfix[i]=product;
    // }

    // //Miltiply postfix and prefix
    // int result=1;

    // for (int i = 0; i < A.size(); i++)
    // {
    //     if(i==0)
    //         result = 1*postfix[i+1];
    //     else if(i==A.size()-1)
    //         result = prefix[i-1]*1;
    //     else
    //         result=prefix[i-1]*postfix[i+1];

    //         finalVec.push_back(result);

    // }
    
    

    //Bruteforce Approach
    // for (size_t i = 0; i < A.size(); i++)
    // {
    //     product=1;
    //    for (int j = 0; j < A.size(); j++)
    //    {
    //         if(i==j)
    //             continue;
    //         product *= A[j];    
    //    }
    //     finalVec.push_back(product);
       
    // }


   
    
    return 0;
}