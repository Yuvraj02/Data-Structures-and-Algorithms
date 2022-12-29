#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

    string s = "abcabcbb";

    unordered_map<char,int> m;
    int left=0,right=0,n=s.size(),maxLen=INT32_MIN;

    while (right<n)
    {
        auto it = m.find(s[right]);

        if(it != m.end()){
            left = max(left, (it->second)+1);
            m.erase(it);
        }
            m.insert(make_pair(s[right],right));
            maxLen = max(maxLen,(right-left)+1);
            cout<<"Left: "<<left<<" "<<"Right: "<<right<<endl;
            right++;
    }
    cout<<maxLen;

    return 0;
}
    
//Bruteforce approach is to check every possible combination of the characters