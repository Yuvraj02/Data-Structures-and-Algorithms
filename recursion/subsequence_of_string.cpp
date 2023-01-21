#include <iostream>
#include <vector>
using namespace std;

void generateSubsequence(string s,string output, int i, vector<string> &final_set){

    if(i>=s.size()){
        final_set.push_back(output);
        return ;
    }

    //Exclude
    generateSubsequence(s,output,i+1,final_set);
    //Include
    output+=s[i];
    generateSubsequence(s,output,i+1,final_set);

}

int main(){

    string s = "abc";
    string output = "";
    vector<string> final_set;

    generateSubsequence(s,output,0,final_set);

    for (int i = 0; i < final_set.size(); i++)
    {
        cout<<final_set[i]<<" ";
    }
    
    return 0;
}