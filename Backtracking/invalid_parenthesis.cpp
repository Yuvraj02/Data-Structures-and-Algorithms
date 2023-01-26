#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;


int getMin(string str){

    stack<char> s;

    for(int i=0;i<str.size();i++){
        
        if(!s.empty() && (str[i]==')' && s.top()=='(')){
            s.pop();
        }else if(str[i]=='(' || str[i]==')'){
            s.push(str[i]);
        }
        
    }
   return s.size();
}

bool validParenthesis(string str){

    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i]!=')'){
            s.push(str[i]);
        }else if(str[i]==')' && s.top()==')'){
            return false;
        }else{
            s.pop();
        }
    }
    
    return true;
}

void solve(string str,int minimum, set<string>& s){

    if(minimum==0){
        int minNow = getMin(str);
        if(minNow==0){
                if(s.find(str) == s.end())
                    s.insert(str);
        }
        return;
    }

    for (int k = 0; k < str.size(); k++)
    {
        string output =""; 
        for (int j = 0; j < str.size(); j++)
        {
            if(k==j)
                continue;

            output+=str[j];
        }
        
        solve(output,minimum-1,s);
    }
}

int main(){

    string brackets = "(a)())()";
    set<string> s;
    vector<string> sv;
    int minimum = getMin(brackets);
    solve(brackets,minimum,s);
    auto it = s.begin();
    while (it!=s.end())
    {
        sv.push_back(*it);
        it++;
    }
    
    for(auto i : sv){
        cout<<i<<", ";
    }

    return 0;
}