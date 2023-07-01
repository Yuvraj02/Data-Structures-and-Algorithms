#include <iostream>

using namespace std;

class heap {
    public:
        int arr[100];
        int size;

        heap(){
            size=0;
        }

        void insert(int data){

            size++;
            int index = size;
            arr[index] = data;

            while(index>1){
                int parent = index/2;

                if(arr[parent] < arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }else{
                    return ;
                }
            }

        }

        void printHeap(){
            for(int i = 1; i<=size; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
        void top(){
            cout<<arr[1]<<endl;
        }

        void del(){
            
            if(size==0){
                cout<<"Nothing to Delete! Heap is Empty";
                return ;
            }

            //Step 1: replace Top with last elemenet
            arr[1] = arr[size];
            size--;

            //Step 2: Bring Node to correct position
            int i = 1;
            while(i<=size){
                int left = 2*i;
                int right = 2*i+1;

                if(left<=size && arr[left] > arr[right] && arr[i] < arr[left]){
                        swap(arr[left],arr[i]);
                        i = left;
                }else if(right <= size && arr[right] > arr[left] && arr[i] < arr[right]){
                    swap(arr[right],arr[i]);
                    i = right;
                }else{
                    return ;
                }
            }
        }
};

void heapify(int arr[], int size, int i){

    int currIndex = i;
    int left = 2*i;
    int right = 2*i+1;
    
    if(left <= size && arr[left] > arr[currIndex]){
        currIndex = left;
    }
    if(right <= size && arr[right] > arr[currIndex]){
        currIndex = right;
    }

    //If the position of current index is changed that means, it has to be swapped with this position
    if(currIndex!=i){
        swap(arr[i],arr[currIndex]);
        //Check if further heapification needed
        heapify(arr,size,currIndex);
    }
}

void heapsort(int arr[], int size){
    
    while(size>1){
        //Step 1: Swap root element with last element
        swap(arr[1],arr[size]);
        //Decrement size
        size--;
        //Step 2: Heapify the root element to it's correct position
        heapify(arr,size,1);
    }

}

int main(){

    heap h;
    
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(35);
    h.insert(27);
    h.insert(22);
    h.insert(9);

    int n = 6;
    int arr[] = {-1,10,20,30,35,27,22};
    
    
    for(int i = n/2; i>=1;i--)
        heapify(arr,n,i);
    
    for(int i = 1; i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr,n);

    for(int i = 1; i<=n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}