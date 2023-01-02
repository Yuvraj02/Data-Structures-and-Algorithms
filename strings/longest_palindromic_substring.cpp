#include <iostream>

using namespace std;

int main(){

    string s = "babad";

    string result = "";

    int resLength = 0;
    for (int i = 0; i < s.size(); i++)
    {
      //  result = "";
        
        int left=i,right=i;

        while ((left>=0 && right<s.size()) && s[left]==s[right])
        {
                if(right-left+1 > resLength){
                    result = "";
                    for (int j = left; j <=right; j++)
                    {
                        result+=s[j];
                    }
                    resLength = right-left+1;
                }
                right++;
                left--;
        }

        left = i;
        right=i+1;

    while ((left>=0 && right<s.size()) && s[left]==s[right])
    {
            if(right-left+1 > resLength){
                result="";
                for (int j = left; j <=right; j++)
                    {
                        result+=s[j];
                    }
                resLength = right-left+1;
            }
            left--;
            right++;
    }
    }
    cout<<result;

    return 0;
}