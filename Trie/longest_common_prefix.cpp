#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;
        int childCount;

        TrieNode(char data){
            this->data = data;
            for(int i=0; i < 26; i++)
                children[i] = NULL;
            
            this->isTerminal = false;
            this->childCount = 0;
        }
};

class Trie{
    public :
        TrieNode *root;
    
    Trie(char ch){
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string word){
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        
        TrieNode *child;

        if(root->children[index] == NULL){
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }else{
            child = root->children[index];
        }
        insertUtil(child,word.substr(1));
    }
    void insert(string word){
        insertUtil(root,word);
    }

    void lcp(string str, string &ans){
        
        for(int i = 0; i<str.length();i++){
            char ch = str[i];
            
            if(root->childCount==1){
                ans.push_back(ch);
                
                int index = ch-'a';
                root = root->children[index];
            }else{
                break;
            }

            if(root->isTerminal)
                break;
        }

    }
};



string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    if(arr.size()==0)
        return "";
    
    Trie *t = new Trie('\0');
    for(int i = 0; i<arr.size();i++)
        t->insert(arr[i]);
    
    //t->insert(arr[0]);

    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);
    
    return ans;
}
