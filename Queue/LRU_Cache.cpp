#include <iostream>
#include <deque>
#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

class LRUCache {
public:
    int size;
    list<pair<int,int>> q;
    unordered_map<int,list<pair<int,int>>::iterator> cache; 


    LRUCache(int capacity) {
        this->size = capacity;    
    }
    
    int get(int key) {
        //If no element exists return -1;
        if(cache.find(key) == cache.end())
            return -1;

        pair<int,int>  data = *cache[key];
        q.erase(cache[key]);
        //Push to front
        q.push_front(data);
        //Update map reference
        cache[key] = q.begin();

        return data.first;

    }
    
    void put(int key, int value) {
        //If element doesn't exists
        if(cache.find(key) == cache.end()){
            //If Cache is full
            if(q.size()==size){
                //Remove least recently used from back
                //Put element to front
                int last = q.back().second;
                q.pop_back();
                cout<<"Removing : "<<last<<endl;
                cache.erase(last);
            }
        }else{
            //If element exists already
             q.erase(cache[key]);
        }
        q.push_front(make_pair(value,key));
        cache[key] = q.begin();
    }

};

int main(){

        LRUCache lruCache(2);
        lruCache.put(1,0);
        lruCache.put(2,2);
        cout<<lruCache.get(1)<<endl;
        lruCache.put(3,3);
        cout<<lruCache.get(2)<<endl;
        lruCache.put(4,4);
        cout<<lruCache.get(1)<<endl;
        cout<<lruCache.get(3)<<endl;
        cout<<lruCache.get(4)<<endl;

    return 0;
}