 #include<iostream>
 #include <list>
 #include <unordered_map>
 #include <utility>

 using namespace std;
 
 class LRUCache {
public:
    int capacity;
    //{key,value}
    list<pair<int,int>> q;
    unordered_map<int,list<pair<int,int>>::iterator> mapp;

    LRUCache(int capacity) {

    this->capacity = capacity;

    }
    
    int get(int key) {
        //if key doesn't exists then return -1
        if(mapp.find(key)==mapp.end())
            return -1;

        //Step 1: Store the data in a variable
        int data = mapp[key]->first;
        //Step 2: Erase the node from the list
        q.erase(mapp[key]);
        //Step 3 : Add a new node to the front of the list with same data
        q.push_front({data,key});
        //Step 4 : Update the entry in the map
        mapp[key] = q.begin();

        //Step 6 : return the data
        return data;
    
    }
    
    void put(int key, int value) {
        
        //If key already exists
        if(mapp.find(key)!=mapp.end()){
           //Then erase the key
            q.erase(mapp[key]);
            mapp.erase(key);
        }else{
            //Check if the q is full or not
                if(q.size()==capacity){
                    //Get last recently used
                    int keyToErase = q.back().second; //{value, key}
                    //Remove last recently used from the 
                    q.pop_back();
                    //Remove last recently used entry from the mapp
                    mapp.erase(keyToErase);
                }
        }
        //Add items
                q.push_front({value,key});
                mapp.insert({key,q.begin()});
    }
};

int main(){

    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    
    cout<<cache.get(4);

    return 0;

}