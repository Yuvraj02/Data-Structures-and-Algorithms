/*
    In a candy store, there are N different types of candies available and the prices of all the
    N different types of candies are provided to you.
    You are now provided with an attractive offer.
    For every candy you buy from the store and get at most K other candies ( all are different types ) for free.
    Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have
    to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money
    you have to spend to buy all the N different candies.
    In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.
*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

 
 vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        
        sort(candies,candies+N);
        // for(int i = 0; i<N;i++){
        //     cout<<candies[i]<<" ";
        // }
        
        int l=0,r=N-1;
        
        int minAmount = 0;
        
        while(l<=r){
            
            minAmount += candies[l];
            r-=K;
            l++;
        }
        
        l =0,r=N-1;
        
        int maxAmount = 0;
        
        while(l<=r){
            maxAmount += candies[r];
            l+=K;
            r--;
        }
        
        return {minAmount,maxAmount};
    }