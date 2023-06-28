#include <iostream>

using namespace std;

class heap{

    public:
        int arr[100];
        int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int data){
        //Step 1 : Insert at last
        size++;
        int index = size;
        arr[index] = data;
        //Step 2 : Swap with parent until either the node becomes root or it's greater than it's children
        while(index > 1){
            
            int parent = index/2;
            //Swap if parent is less (Max Heap property)
            if(arr[parent] < arr[index]){
                
                swap(arr[parent], arr[index]);

                index = parent;
            }else{
                return ;
            }
        }
    }

    void printHeap(){
        for(int i = 1; i<=size; i++)
            cout<<arr[i]<<" ";
    }

    int top(){
        if(size>=1)
            return arr[1];
        
        cout<<"Empty Heap!"<<endl;

        return -1;
    }

};

int main(){

    heap h1;
    h1.insert(20);
    h1.insert(30);
    h1.insert(40);
    h1.insert(50);
    h1.insert(60);
    //cout<<h1.top();
    h1.printHeap();
    return 0;
}