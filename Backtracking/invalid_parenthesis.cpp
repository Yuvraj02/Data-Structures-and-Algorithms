#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <string.h>
using namespace std;

int getMin(string str){

    stack<int> s;

    for(int i=0;i<str.size();i++){
        if(!s.empty() && (str[i]==')' && s.top()=='(')){
            s.pop();
        }else if(str[i]=='(' || str[i]==')'){
            s.push(str[i]);
        }
    }
return s.size();
}


void solve(string str, vector<string> &ans, int min,set<string>& s){

    if(min==0){
        if(getMin(str)==0){
                if(s.find(str)==s.end()){
                    ans.push_back(str);
                    s.insert(str);
                }
        }
        return;
    }

    for(int i = 0;i<str.size();i++){
         string output = str.substr(0,i);
         output += str.substr(i+1);      
         solve(output,ans,min-1,s);
    }

}


int main(){

    string str = "()(((((((()";
   
    int minInvalid = getMin(str);
    vector<string> ans;
    set<string> s;
    solve(str,ans,minInvalid,s);

    //cout<<minInvalid;
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}