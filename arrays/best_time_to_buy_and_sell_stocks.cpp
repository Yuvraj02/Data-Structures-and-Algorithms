#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    int maxProfit=0,minValue=INT32_MAX,maxValue=INT32_MIN,day;
    //Bruteforce Approach----
    // for (int i = 0; i < prices.size(); i++)
    // {
    //     for (int j = i+1; j < prices.size(); j++)
    //     {
    //         if(prices[i]>prices[j])
    //             continue;
            
    //         maxProfit = max(maxProfit, prices[j]-prices[i]);
    //     }   
        
    // }


    //Slightly Optimized Approach

    // for (int i = 0; i < prices.size(); i++)
    // {
    //     // minValue = min(minValue,prices[i]);
    //     if(prices[i]<minValue){
    //         minValue=prices[i];
    //         day = i;
    //     }

    // }

    // for (int i = day+1; i < prices.size(); i++)
    // {
    //     maxValue = max(maxValue,prices[i]);
    // }

    //   if(maxValue!=INT32_MIN){
    //     maxProfit = maxValue-minValue;
    //   }  

    //Optimized Approach
    int L=0,R=1;
        
        while (R<prices.size())
        {
            if(prices[R]>prices[L]){
                maxProfit = max(maxProfit,prices[R]-prices[L]);
   
            }else{
                L=R;
                
            }
            R++;
        }
        

    // for (int i = 0; i < prices.size(); i++)
    // {
    //         if()
    // }
    cout<<maxProfit;
    
   // cout<<maxProfit;
    return 0;
}