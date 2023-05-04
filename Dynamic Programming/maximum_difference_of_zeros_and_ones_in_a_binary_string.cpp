#include <iostream>

using namespace std;

int maximumDifference(string &str)
{

    int sum = 0;
    int maxLen = -1;

    for(int i = 0; i<str.size();i++){

            if(str[i]=='1')
                sum+=-1;

            if(str[i]=='0')
                sum+=1;

            maxLen = max(maxLen,sum);

            if(sum < 0)
                sum = 0;
    }

    return maxLen;
}

int main(){

    string s = "11000001100111";
    cout<<maximumDifference(s);
    return 0;
}