 #include <iostream>
 #include <vector>
 #include <unordered_map>

 using namespace std;
 
 vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int,int> m;
        vector<int> v;
        int dist_count = 0;
        
        for(int i = 0 ; i < k;i++){
            
            if(m[A[i]]==0){
                m[A[i]] = 1;
                dist_count++;
            }else{
                m[A[i]]++;
            }
           
        }

     v.push_back(dist_count);
        
        for(int i=k;i<n;i++){
            
            if(m[A[i-k]]==1){
                dist_count--;
            }
            
            m[A[i-k]]--;
            
            if(m[A[i]]==0){
                m[A[i]] = 1;
                dist_count++;
            }else{
                m[A[i]]++;
            }
            
            v.push_back(dist_count);
        }
        
    return v;    
    }

int main(){

    int A[] = {1,2,1,3,4,2,3};

    int n = sizeof(A)/sizeof(A[0]);

    int k = 4;

    for(auto i : countDistinct(A,n,k))
        cout<<i<<" ";

    return 0;
}