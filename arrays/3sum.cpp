#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> A = {0,0,0};
    vector<vector<int>> finalVec; 
    sort(A.begin(),A.end());


    // for (auto i : A)
    // {
    //     cout<<i<<" ";
    // }
    

    for (int i = 0; i < A.size(); i++)
    {   
                if(i>0 && A[i]==A[i-1])
                    continue;
                    
           int L=i+1;
           int R=A.size()-1;

            while (L<R)
            {
                if(A[i]+A[L]+A[R]==0){
                    finalVec.push_back({A[i],A[L],A[R]});
                    L++;
                    while (L<R && A[L]==A[L-1])L++;
                }else if(A[i]+A[L]+A[R]<0){
                    L++;
                }else{
                    R--;
                }

            }
    }

 for (int i = 0; i < finalVec.size(); i++)
    {
        for (int j = 0; j < finalVec[i].size() ; j++)
        {
            cout<<finalVec[i][j]<<" ";
        }
        cout<<"\n";
    }

    //Bruteforce Approach
    // int sum = 0;
    // vector<vector<int>> triplets;
    // for (int i = 0; i < A.size(); i++)
    // {
    //         for (int j = i+1; j < A.size(); j++)
    //         {   
                
    //             for (int k = j+1; k < A.size(); k++)
    //             {  
    //                 vector<int> elems;
    //                 if(A[i]+A[j]+A[k]==0){
    //                     elems.push_back(A[i]);
    //                     elems.push_back(A[j]);
    //                     elems.push_back(A[k]);
    //                 }
    //                 triplets.push_back(elems);    
    //             }
                
    //         }
    // }
        
    
    

    return 0;
}