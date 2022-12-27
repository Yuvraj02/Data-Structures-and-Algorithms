#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <iomanip>
using namespace std;

bool uniqueOccurences(vector<int> arr){

    int count=0;
    map<int,int> m;

    for (int i = 0; i < arr.size(); i++)
    {   
            count=1;
            auto it = m.find(arr[i]);

            if(it != m.end()){
                count=it->second;
                count++;
                it->second = count;
            }else{
                m.insert(make_pair(arr[i],count));

            }
    }
    
        unordered_set<int> s;
        auto it = m.begin();
        int num;
        for (it; it != m.end(); it++)
        {
            auto itr = s.find(it->second);
            if(itr!=s.end())
                return false;
            else
                s.insert(it->second);
        }
     return true;
}

int main(){

    vector<int> arr = {26,2,16,16,5,5,26,2,5,20,20,5,2,20,2,2,20,2,16,20,16,17,16,2,16,20,26,16};
    
    cout<<boolalpha<<uniqueOccurences(arr)<<endl;

    return 0;
}