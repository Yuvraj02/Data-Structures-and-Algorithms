#include <iostream>
#include <set>

using namespace std;

 bool buddyStrings(string s, string goal) {

       if(s==goal){

            //If the strings are equal then put s to a set
            //if the size becomes lower than goal, that means
            //there were duplicate characters, so we can swap
            // any of the duplicate characters to get same string
           set<char> temp(s.begin(),s.end());
           return temp.size() < goal.size();
       } 

        int i = 0;
        int j = goal.size()-1;

        //Find a different character from the left of s
        while(s[i]==goal[i] && i < s.size()) i++;
        //Find a different character from the right of s
        while(s[j]==goal[j] && j>=0) j--;

        //swap these characters
        swap(s[i],s[j]);

        //Return if the string is equal or not
        return s==goal;

}

int main(){

    string s = "aaab";
    string goal = "aaba";

    cout<<buddyStrings(s,goal);

    return 0;
}