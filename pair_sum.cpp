#include <iostream>

using namespace std;

//TODO: Optimize The solution

//----------Bruteforce Approach
 int getPairsCount(int arr[], int n, int k) {

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if(i==j)
                continue;

                if (arr[i]+arr[j]==k)
                {
                    count++;
                }
                
            }
            
        }
        
    return count;
    
    }
int main(){

    int n = 4,k=2;
    int arr[n] = {1,1,1,1}; 

    cout<<getPairsCount(arr,n,k);
    return 0;
}