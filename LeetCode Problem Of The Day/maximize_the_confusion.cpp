#include <unordered_map>
#include <iostream>

using namespace std;

int maxConsecutiveAnswers(string answerKey, int k) {

        unordered_map<char,int> mapp;
        
        int right=0,left=0,max_size=INT32_MIN;

        for(int right = 0; right<answerKey.size();right++){

            mapp[answerKey[right]]++;

            int most_freq = 0;
            //Get most frequent character of the window
            for(auto it = mapp.begin();it!=mapp.end();it++)
                most_freq = max(most_freq, it->second);
            
            //While the operations are more than given, decrement window size 
            while(right-left+1 - most_freq > k){
                mapp[answerKey[left]]--;
                left++;
            }
            max_size = max(max_size,right-left+1);
        }
        return max_size;
    }

int main(){

    string answerKey = "TTFF";
    int k = 2;
    cout<<maxConsecutiveAnswers(answerKey,k);

    return 0;
}