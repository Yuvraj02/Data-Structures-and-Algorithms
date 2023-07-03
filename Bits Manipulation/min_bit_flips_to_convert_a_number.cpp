#include <iostream>

using namespace std;


int minBitFlips(int start, int goal) {
        
        int n = start^goal;

        long long count = 0;

        while(n){
            n=n&(n-1);
            count++;
        }
        return count;
    }