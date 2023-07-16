 #include <iostream>
 #include <vector>

 using namespace std;

long long int longestSubarry(long long int A[], long long int N) {
    
    long long l = 0;
    long long r = 0;
    int sum = 0;
    long long maxLength = 0;
    
    for(r; r<N;r++){
        
        if(A[r] >= 0)
            sum+=A[r];
        else
            l = r+1;
        
        maxLength = max(maxLength,r-l+1);
        
    }
    
    return maxLength;
}