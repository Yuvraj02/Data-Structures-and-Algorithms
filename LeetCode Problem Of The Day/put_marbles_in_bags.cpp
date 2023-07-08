 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;


 long long putMarbles(vector<int>& weights, int k) {
        
        vector<long long> adjSum;

        long long mini = weights[weights.size()-1] - weights[0];
        long long maxi = weights[weights.size()-1] - weights[0];

        for(int i = 0; i < weights.size()-1;i++)
            adjSum.push_back(weights[i] + weights[i+1]);

        sort(adjSum.begin(),adjSum.end());


        for(int i = 0; i<k-1; i++){
            mini += adjSum[i];
            maxi += adjSum[adjSum.size()-1-i];
        }
        return maxi-mini;
    }

int main(){
vector<int> weights = {1,3,5,1};
int k = 2;
cout<<putMarbles(weights,k);
return 0;
}