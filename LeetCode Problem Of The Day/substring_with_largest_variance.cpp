#include <iostream>
#include <algorithm>

using namespace std;


int largestVariance(string s) {
    int variance = 0;
    //Calculate Frequencies for both characters
    int f1 = 0,f2=0;

    //Do operations 2 times, one for original string and then other for reversed string
    for(int i = 0; i<2;i++){
       
        //Take First character a
        for(char a = 'a'; a<='z';a++){
            //Take second character b and then check for their count
            for(char b = 'a';b<='z';b++){
                if(a==b) continue;
                //Set frequencies to 0
                f1=f2=0;
                //Now compare each character of string with a and b
                for(auto ch : s){
                    if(ch!= a && ch!=b)
                        continue;
                    
                    if(ch==a)
                        f1++;
                    if(ch==b)
                        f2++;
                    
                    //If freq of 2nd char is greater, then reset
                    if(f2 > f1)
                        f1=f2=0;
                    
                    if(f1 > f2 && f2!=0)
                        variance = max(variance,f1-f2);
                }
            }
        }
        //Reverse to check from other direction
        reverse(s.begin(),s.end());
    }
    return variance;
}

int main(){

    string s = "aababbb";
    cout<<largestVariance(s);

    return 0;
}