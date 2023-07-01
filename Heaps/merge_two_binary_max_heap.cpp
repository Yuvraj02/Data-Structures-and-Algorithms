 #include <iostream>
 #include <vector>

using namespace std;
 
 void heapify(vector<int> &a, int &n, int i){
        //cout<<"Reached the function"<<" ";
        
        int currIndex = i;
        int left = (2*i)+1;
        int right = (2*i)+2;
        
        if(left<n && a[left] > a[currIndex]){
            //cout<<"Pos changed";
            currIndex = left;
        }
        
        if(right < n && a[right] > a[currIndex]){
            currIndex = right;
        }
        
        //Check if current Pos is updated or not, if yes, then swap values and perform heapify further
        if(currIndex != i){
          //  cout<<"S";
            swap(a[currIndex], a[i]);
            heapify(a,n,currIndex);
        }
            
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        //Step 1 : merge both the vectors
        vector<int> c;
        
        for(auto i : a){
            c.push_back(i);
        }
        
        for(auto i : b){
            c.push_back(i);
        }
        
        //Step 2: Heapify this array
        int size = c.size();
        
        for(int i = (size/2)-1; i>=0 ;i--){
           // cout<<i<<" ";
            heapify(c,size,i);
        }
        
        return c;
    }