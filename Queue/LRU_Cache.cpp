#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *previous;
        
    Node(int val){
        this->data = val;
        next = NULL;
        previous = NULL;
    }

};

class LRUCache {
public:
    int val;
    int size;
    Node *head;
    Node *tail;
    unordered_map<int,Node> cache; 

    LRUCache(int capacity) {

    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        
    }
};

int main(){


    return 0;
}