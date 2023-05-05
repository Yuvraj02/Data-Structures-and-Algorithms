#include <iostream>
#include <vector>

using namespace std;


int kadane(vector<int> A){
        int sum = 0;
        
        int maxSum = 0;
        
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            
            maxSum = max(sum,maxSum);
            
            if(sum<0)
                sum=0;
        }
        return maxSum;
    }
  
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        
        int totalMax = 0;
        
       
        for(int lcolumn = 0; lcolumn<C; lcolumn++){
             
            vector<int> adder(R,0);
            for(int rcolumn = lcolumn; rcolumn<C ;rcolumn++){
                    
                    //Add Right column to left Column
                    for(int i = 0; i<R; i++){
                        adder[i] += M[i][rcolumn];
                    }
                    
                    //Use kadane's algo
                 int maxSum = kadane(adder);
                    
                totalMax = max(totalMax,maxSum);    
            }
        }
        
        if(totalMax==0)
            return -1;
        else
            return totalMax;
    }

    int main(){

        vector<vector<int>> A = {{1,2,-1,-4,-20},
{-8,-3,4,2,1},
{3,8,10,1,3},
{-4,-1,1,7,-6}};

int R = A.size();
int C = A[0].size();
cout<<maximumSumRectangle(R,C,A);

        return 0;
    }

