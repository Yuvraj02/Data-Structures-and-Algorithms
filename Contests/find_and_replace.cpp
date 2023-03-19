#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        unordered_map<char, char> mapp;
        char init = s[0];

        mapp[init] = '0';
        // mapp[s[1]] = '1';
        s[0]='0';
       // cout<<s;
        bool replacable = true;
        for (int i = 1; i < n; i++)
        {
            char ch = s[i];
            if(mapp.find(ch)==mapp.end()){
                    //If preceding char is 0 and current char isn't in mapp
                    if(s[i-1]=='0'){
                        s[i]='1';
                        mapp[ch] = '1';
                    }else{
                        s[i]='0';
                        mapp[ch] = '0';
                    }
            }else{
                s[i] = mapp[ch];
                if(s[i]==s[i-1]){
                    replacable=false;
                    break;
                }
            }
        }

        if(replacable)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }

    return 0;
}