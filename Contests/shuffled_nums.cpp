#include <iostream>
#include <vector>
using namespace std;


void generatePerm(string s,vector<string>&ans,int index){
    
    if(index>=s.size()){
        ans.push_back(s);
       // cout<<"didn't reach";
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        swap(s[i],s[index]);
        generatePerm(s,ans,i+1);
        swap(s[i],s[index]);
    }

}

int main(){

    string s = "abc";
    vector<string> ans;
    generatePerm(s,ans,0);
    //cout<<ans.size();
    for (int i = 0; i < ans.size(); i++)
    {
        
        cout<<ans[i]<<" ";
    }

    
    return 0;
}