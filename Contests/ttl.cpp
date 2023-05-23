#include <iostream>
#include <vector>

using namespace std;

vector<int> getCacheSize(vector<vector<int>> data,vector<int> queries ){

    int startTime = queries[0];
    int endTime = queries[1];

    vector<int> liveData;

    for(int i=0;i<data.size();i++){

        if((data[i][0] + data[i][1]) >= startTime && (data[i][0] + data[i][1]) >= endTime)
            liveData.push_back(i+1);
    }
    return liveData;
}

int main(){

    vector<vector<int>> data = {{105231,183},
                                {105334,34},
                                {105198,543}};

    vector<int> queries = {105338,105410};

    for(auto i : getCacheSize(data,queries))
        cout<<i<<" ";

    return 0;
}