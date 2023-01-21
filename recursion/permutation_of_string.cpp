#include <iostream>
#include <vector>

using namespace std;

void solve(string str,int i, vector<string> &permutations){

    if(i>=str.size()){
        permutations.push_back(str);
    }

    for(int k=i;k<str.size();k++){
        swap(str[i],str[k]);
        solve(str,i+1,permutations);
        swap(str[i],str[k]);
    }

}

int main(){
    string str = "abc";
    vector<string> permutations;  

    solve(str,0,permutations);

    for(auto i : permutations){
        cout<<i<<" ";
    }

    return 0;
}