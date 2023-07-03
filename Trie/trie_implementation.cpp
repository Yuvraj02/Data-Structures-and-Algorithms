#include <iostream>

using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;

        TrieNode(char data){
            this->data = data;
            for(int i = 0; i<26; i++)
                children[i] = NULL;

            this->isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode *root;
        
        Trie(){
            root = new TrieNode('\0');
        }

        void insert(TrieNode *root, string word){

            if(word.size()==0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'a';
            TrieNode *child;

            //Now we have two cases
            //case 1 : if the letter(node) is present in trie
            //case 2 : if the letter(node) is not present in trie
            if(root->children[index]==NULL){
                //If the letter is absent
                child = new TrieNode(word[0]);
                //Now add this child node to root's child
                root->children[index] = child;
            }else{
                //If present
                child = root->children[index];
            }

            insert(child,word.substr(1));
        }

        void insertWord(string word){
                insert(root,word);
        }

        bool search(TrieNode *root, string word){
            
            if(word.size()==0)
                return root->isTerminal;
            
            int index = word[0] - 'a';

            if(root->children[index] == NULL){
                return false;
            }else{
                return search(root->children[index], word.substr(1));
            }

        }

        bool searchWord(string word){
            return search(root,word);
        }


        void removeWord(TrieNode *root, string word){

            if(word.size()==0){
                if(root->isTerminal){
                    root->isTerminal = false;
                    cout<<"Removed"<<endl;
                }
                else
                    cout<<"Word is Not Present"<<endl;
                return;
            }
            int index = word[0] - 'a';

            if(root->children[index]!=NULL){
                removeWord(root->children[index],word.substr(1));
                root->children[index] = NULL;
            }else{
                cout<<"Word is Not present"<<endl;
                    return;
            }
        }

        void remove(string word){

             removeWord(root,word);

        }

        bool searchPrefix(TrieNode *root, string word){

        if(word.size()==0)
            return true;
        
        int index = word[0] - 'a';

        if(root->children[index]==NULL)
            return false;
        
        return searchPrefix(root->children[index], word.substr(1));
        }


        bool startsWith(string prefix){
            return searchPrefix(root,prefix);
        }

};

int main(){

    Trie *t = new Trie();
    string word = "coding";
    t->insertWord(word);
    cout<<t->searchWord(word)<<endl;
    t->remove(word);
    //cout<<t->root->children[0]->data;
    //t->remove(word);
    return 0;
}