 #include <iostream>
 #include <vector>
 #include <queue>
 #include <unordered_map>

using namespace std;

void merge(int arr[], int start, int end, unordered_map<int,int> &count){
        
        //Create arrays of 2 sizes
        int mid = (start+end)/2;
        int len1 = mid-start+1;
        int len2 = end-mid;
        
        vector<int> A(len1);
        vector<int> B(len2);
        
        //Pointer for actual Array
        int k = start;
        
        for(int i = 0; i<len1;i++){
            A[i] = arr[k++];
        }
        
        //Bring k to the mid
        k = mid+1;
        
        for(int i = 0; i<len2; i++){
            B[i] = arr[k++];
        }
        
        //Now merge two sorted arrays
        
        int i = 0,j=0;
        k=start;
        
        //Inversion Count
        int cnt = 0;
        while(i<len1 && j<len2){
            if(A[i]<=B[j]){
                count[A[i]] += cnt;
                arr[k++] = A[i++];
            }else{
                arr[k++] = B[j++];
                cnt++;
              //  cnt+= (mid+1)-(start+i);
            }
        }
        
        //For remaining elements
        while(i<len1){
            count[A[i]] += cnt;
            arr[k++] = A[i++];
            
        }
        while(j<len2)
            arr[k++] = B[j++];
    }    
    
    void mergeSort(int arr[],int start, int end, unordered_map<int,int> &count){
            
            if(start >= end)
                return;
                
            int mid = (start+end)/2;
            mergeSort(arr,start,mid,count);
            mergeSort(arr,mid+1, end,count);
            merge(arr,start,end,count);
            
    }

    vector<int> findSurpasser(int arr[], int n) {
        // code here
        vector<int> ans;
        unordered_map<int,int> count;
        int helper[n];
        memcpy(helper,arr,n*sizeof(arr[0]));
        mergeSort(helper,0,n-1,count);
        
        //Now inverting the count and push it to ans vector
        for(int i = 0; i<n;i++){
            ans.push_back((n-1) - i - count[arr[i]]);
        }
        
        return ans;
    }