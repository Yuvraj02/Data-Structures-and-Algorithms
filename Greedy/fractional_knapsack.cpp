#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};

 
 double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        //{Total value, weight}
        vector<pair<double,double>> profit_per_weight;
        for(int i = 0; i<n;i++){
            profit_per_weight.push_back({(1.0*arr[i].value)/arr[i].weight,arr[i].weight});
        }
        
        //Sort according to the p/w values
        sort(profit_per_weight.begin(),profit_per_weight.end(),greater<pair<double,double> >());
        
        //Now start calculation
        double profit = 0.0;
        
        for(int i = 0; i<n; i++){
            
            //If we can include the item with full weight, then include it
            if(W - profit_per_weight[i].second >= 0){
                profit += profit_per_weight[i].first * profit_per_weight[i].second;
                W -= profit_per_weight[i].second;
            }else{
                profit += profit_per_weight[i].first * W;
                break;
            }
                    
        }
        return profit;
    }