#include <iostream>
#include <vector>
#include <math.h>
using namespace std;



int main(){

    vector<int> A = {1,1};
    long long int N = A.size(),summation=0,answer=0,finalSum=0;

    for (int i = 0; i < N; i++)
    {

            for (int j = 0; j < N; j++)
            {

                for (int k = i; k <=j; k++)
                {
                   summation+=A[k];

                }
                answer+=summation;
                
            }

    }


    return 0;
}