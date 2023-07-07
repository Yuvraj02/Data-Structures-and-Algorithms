 #include <iostream>

 using namespace std;

 
 void heapify(int arr[], int size, int i)  
    {
      // Your Code Here
      int currIndex = i;
      int left = 2*i+1;
      int right = 2*i+2;
      
      if(left <= size && arr[left] > arr[currIndex])
        currIndex = left;
        
        if(right <= size && arr[right] > arr[currIndex])
            currIndex = right;
            
        if(currIndex != i){
            swap(arr[i], arr[currIndex]);
            heapify(arr,size,currIndex);
        }
    }

    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        for(int i = (n/2)-1; i>=0; i--)
            heapify(arr,n-1,i);

    }

    
   
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        //Step 1: Build Heap
        buildHeap(arr,n);
        
        int size = n-1;
        while(size>=0){
            //Swap last element with first
            swap(arr[0],arr[size]);
            
            //Decrement size
            size--;
            
            //heapify the root node
            heapify(arr,size,0);
            
        }
        
    }