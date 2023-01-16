#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> A = {-2,-1,-1,1,1,1,2,2};
    int target = 0;
    vector<vector<int>> vec;
               
    sort(A.begin(),A.end());
    
          for(int i=0;i<A.size();i++){

                if(i>0 && A[i]==A[i-1])
                    continue;

                for ( int j = i+1; j < A.size(); j++)
                {
                        if(j>i+1 && A[j]==A[j-1])
                            continue;
                
                        int left = j+1,right=A.size()-1;
                        
                        while (left<right)
                        {
                           int sum = A[i]+A[j]+A[left]+A[right];
                            if(sum<target){
                                left++; 
                            }else if(sum>target){
                                right--;   
                            }else{
                                vec.push_back({A[i],A[j],A[left],A[right]});
                                left++;
                                while(left < right && A[left]==A[left-1]) left++;
                                right--;
                                while(left<right && A[right]==A[right+1]) right--;
                            }
                        }
                }
          }
        

          //if(vec.size()==)

    for(int i = 0; i<vec.size();i++){
        for(int j = 0; j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
    

    return 0;
}