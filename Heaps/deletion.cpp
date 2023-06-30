#include <iostream>
#include <vector>

using namespace std;

class heap{

    public:
        int arr[100];
        int size;
    
    heap(){
        size = 0;
    }

    // void insert(int data){

    //     size++;
    //     int index = size;
    //     arr[index] = data;
        
    //     while(index > 1){
    //         int parent = index/2;    
    //         if(arr[parent]<arr[index]){
    //             swap(arr[parent],arr[index]);

    //             index = parent;
    //         }else{
    //             return ;
    //         }
    //     }
    // }
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

    void top(){
        cout<<arr[1]<<endl;
    }

    void printHeap(){
       for(int i = 1; i<=size;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }

    void del(){
        
        if(size==0){
            cout<<"Nothing to Delete";
            return;
        }

        //Step 1 : replace the top with last node
        arr[1] = arr[size];
        size--;
        
        //Step 2 : now bring the top to correct position
        int index = 1;
        
        while(index<=size){

        int left = 2*index;
        int right = 2*index+1;    
            
            //If left child is greater than right child and the current index, then swap with left child
            if(left <= size && arr[index] < arr[left] && arr[left] > arr[right]){  
                swap(arr[left],arr[index]);
                index = left;
            }else if(right<=size && arr[index] < arr[right] && arr[right] > arr[left]){
                swap(arr[right],arr[index]);
                index = right;
            }else{
                return ;
            }
        }
    }
};


int main(){

    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(9);
    // h.insert(7);
    // h.insert(50);
    h.printHeap();
    h.del();
    h.printHeap();
    h.del();
    h.printHeap();
    

    return 0;
}