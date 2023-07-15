#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main(){

    vector<string> a = {"acd", "dfg", "wyz", "yab", "mop","bdfh", "a", "x", "moqs"};
    
    unordered_map<string,vector<string>> mapp;
    
    int diff = 0;
    for(int i = 0; i<a.size();i++){
        if(a[i].size()==1){
            mapp["0"].push_back(a[i]);
            continue; 
        }

        diff = 0;
        string pattern = "";
        for(int j = 0; j<a[i].size()-1; j++){
                
                if(a[i][j] < a[i][j+1])
                    diff = (a[i][j+1] - 'a') - (a[i][j]-'a');    
                else
                    diff = 26 - ((a[i][j] - 'a') - (a[i][j+1]-'a'));
                pattern += to_string(diff);
        }
        
        mapp[pattern].push_back(a[i]);
    }

    for(auto i : mapp){
        cout<<i.first<<"---> ";
        for(auto j : i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}