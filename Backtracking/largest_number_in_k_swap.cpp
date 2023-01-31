#include <iostream>
#include <string>
using namespace std;

void solve(string str, int mainIndex, int k,string &largest){

    
        if(str>largest){
            //ans = stoi(str);
            largest = str;
        }

    if(k==0){
            
        return ;
    }

    for (int i = 0; i < str.size(); i++)
    {
        for (int j = i+1; j < str.size(); j++)
        {
            if(str[i]<str[j]){
            swap(str[i],str[j]);
            solve(str,i+1,k-1,largest);
            swap(str[i],str[j]);
            }
            
        }
        
    }
    
}

int main(){

    int k = 3;
    string str = "1234567";

    int ans = INT32_MIN;
    string largest;
    solve(str,0,k,largest);
    cout<<largest;
    return 0;
}