#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s,int start,int end){

   while (start<=end)
   {
    if(s[start++]!=s[end--])
        return false;
   }

return true;
}

void solve(string s, vector<string> output, vector<vector<string>> &ans,int i){

    if(i==s.size()){
        ans.push_back(output);
        return;
    }


    for(int j=i;j<s.size();j++){
        if(isPalindrome(s,i,j)){
            //This Means that i to j is palindrome,
            //so add it
            output.push_back(s.substr(i,j-i+1));
            solve(s,output,ans,j+1);
            output.pop_back();
        }
        
    }

}

int main(){

    string s = "aab";
    vector<string> output;
    vector<vector<string>> ans;
    string word = "";
    solve(s,output,ans,0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<"[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<",";
        }
        cout<<"] ";
    }
    

    return 0;
}