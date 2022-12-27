#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs){

    
    string prefix=strs[0];
    bool isPrefix = 1;

    string last = "";
    for (int i = 0; i < prefix.size(); i++)
    {
        for (int j = 1; j < strs.size(); j++)
        {   

             if (prefix[i]!=strs[j][i])
             {
                isPrefix=0;
             }
        }
        if(isPrefix)
            last+=prefix[i];
        else
            break;
    }
    
    return last;
}


int main(){

    vector<string> strs = {"flower","flow","flight"};

    cout<<longestCommonPrefix(strs);

    return 0;
}