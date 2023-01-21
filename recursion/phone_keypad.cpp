#include <iostream>
#include <vector>

using namespace std;

void generateCombinations(string number, string output, int i, vector<string> &final_combination,vector<string> &keypad){
    if(number=="") return;
    if(i>=number.size()){
        final_combination.push_back(output);
        return;
    }

    int digit = number[i] - '0';
    string value = keypad[digit];

    for(int j = 0; j<value.size();j++){
        output.push_back(value[j]);        
        generateCombinations(number,output,i+1,final_combination,keypad);
        output.pop_back();
    }    


}


int main(){

    vector<string> A = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string number = "23";
    string output="";
    vector<string> final_combination;

    generateCombinations(number,output,0,final_combination,A);

    for(auto i : final_combination){
        cout<<i<<" ";
    }

    return 0;
}