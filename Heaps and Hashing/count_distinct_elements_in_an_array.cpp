 #include <iostream>
 #include <vector>
 #include <unordered_map>

 using namespace std;


 
 vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int,int> freq;
        
        int count_distinct = 0;
        vector<int> ans;
        for(int i = 0; i<k;i++){
            if(freq[A[i]]==0){
                count_distinct++;
            }    
            freq[A[i]]++;
        }
        
        ans.push_back(count_distinct);
        
        for(int i = k; i<n;i++){
            
            if(freq[A[i-k]]==1)
                count_distinct--;
            
            //Remove the element from the window
            freq[A[i-k]]--;
            
            if(freq[A[i]]==0)
                count_distinct++;
            
            freq[A[i]]++;
            ans.push_back(count_distinct);
        }
        
        return ans;
    }

    int main(){

        int A[] = {1,2,1,3,4,2,3};
        int K = 4; // Window Size
        int N = 7;
        for(auto i : countDistinct(A,N,K)){
            cout<<i<<" ";
        }

        return 0;
    }