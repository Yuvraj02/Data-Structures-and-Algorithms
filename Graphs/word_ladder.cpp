 #include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <list>
#include <unordered_set>

using namespace std;
 
 int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> words(wordList.begin(),wordList.end());
       
        //{Word, Step}
        pair<string,int> begin = {beginWord,1};

        queue<pair<string,int>> q;
        words.erase(beginWord);
        q.push(begin);


        

        while(!q.empty()){
            pair<string,int> front = q.front();
            q.pop();

            string word = front.first;
            int step = front.second;
            if(word==endWord)
                return step;
            //change each letter and check if it exists in the list, if yes, then remove from set and push in queue

            for(int i = 0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z';ch++){
                    //Change letter and check
                    word[i] = ch;
                    if(words.find(word) != words.end()){
                        q.push({word,step+1});
                        words.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }