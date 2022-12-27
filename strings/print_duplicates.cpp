#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    string s = "test string";

    unordered_map<char,int> map;

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]==' ')
            continue;

        auto it = map.find(s[i]);

        if(it != map.end()){
            it->second++;
        }else{
            map.insert(make_pair(s[i],1));
        }
    }
    
    auto it = map.begin();

    for (it; it != map.end(); it++)
    {
        if(it->second > 1)
            cout<<it->first<<", count="<<it->second<<endl;
    }
    
}