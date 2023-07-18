
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
    void reverse(string &s){
        int i = 0;
        int j = s.size()-1;
        
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        
    }
    string reverseWords(string s) 
    { 
        // code here 
        string ans = "";
        
        for(int i = s.size()-1; i>=0; i--){
            
            string word = "";
            
            while(i>=0 && s[i]!='.'){
                
                word+=s[i];
                i--;
            }
        
            //word.push_back("");
            reverse(word);
            word.push_back('.');
            ans += word;
        }
        ans.pop_back();
        return ans;
        
    } 