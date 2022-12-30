#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    string s = "AABABBA";
    int k = 1;
  //ABBBA
    int L=0,R=0,maxLength = INT32_MIN,freq=INT32_MIN;

    unordered_map<char,int> m;

    while (R<s.size())
    {
        
        if(m.find(s[R])==m.end())
            m.insert(make_pair(s[R],1));
        else
            m.find(s[R])->second++;
   
       auto maxFreq = m.begin();
       while (maxFreq!=m.end())
       {    
            freq = max(freq,maxFreq->second);
            maxFreq++;
       }
       
       while (R-L+1 - freq > k)
       {
            m.find(s[L])->second--;
            L++;
       }
       
    maxLength = max(maxLength,R-L+1);
    R++;   
    }
    cout<<maxLength;

  //Bruteforce Solution
  
    // int k=2,dummy=k;

    // int count=0,maxLen = INT32_MIN;

    // for (int i = 0; i < s.size(); i++)
    // {
    //     dummy=k;
    //     count=0;
    //         for (int j = i+1; j < s.size(); j++)
    //         {
    //             if(dummy==0 && s[i]!=s[j])
    //                 break;

    //             if(s[i]!=s[j]){
    //                 dummy--;
    //             }
    //             count++;
    //         }
    //     maxLen = max(count,maxLen);
    // }
    
    // cout<<maxLen+1;

    return 0;
}