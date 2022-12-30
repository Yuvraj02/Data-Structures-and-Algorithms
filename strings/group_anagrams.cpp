#include <iostream>
#include <map>
#include <vector>

using namespace std;


map<char,int> frequenMap(string s){

    map<char,int> frequencyMap;
    for (int i = 0; i < s.size(); i++)
    {
        if(frequencyMap.find(s[i]) == frequencyMap.end())
            frequencyMap.insert(make_pair(s[i],1));
        else
            frequencyMap.find(s[i])->second++;
    }

    return frequencyMap;

}

int main(){

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    map<map<char, int>, vector<string>> m;
    vector<vector<string>> stringVec;
    for (int i = 0; i < strs.size(); i++)
    {
        auto it = m.find(frequenMap(strs[i]));
        if(it!=m.end()){
                it->second.push_back(strs[i]);
        }else{
                vector<string> st= {strs[i]};
                m.insert(make_pair(frequenMap(strs[i]),st));
        }
    }

    auto it = m.begin();
    while (it!=m.end())
    {
        stringVec.push_back(it->second);
        it++;
    }
      
    return 0;
}