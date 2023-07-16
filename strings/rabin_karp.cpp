 #include <iostream>
 #include <vector>


 using namespace std;

int strstr(string s, string x)
{
     //Your code here
     
     //Rabing Karp
     int k = x.size();
     int pattern_sum = 0;
     
     //Calculate Pattern sum
     for(int i = 0; i<k;i++){
         pattern_sum+= x[i] - 'a';
     }
     
     //Calculate win_sum
     int win_sum = 0;
     for(int i = 0; i<k; i++){
        
        win_sum += s[i] - 'a';
     }
     
     //If sum is equal then check for characters
     bool same = false;
     if(pattern_sum==win_sum){
        for(int i = 0;i<k;i++){
            if(s[i]!=x[i])
                break;
        }
        
        return 0;
     }
     
     for(int i = k; i<s.size();i++){
        
        win_sum -= s[i-k];
        win_sum += s[i];
        
        if(pattern_sum==win_sum){
        for(int j = i-k+1;j<k;i++){
            if(s[j]!=x[j])
                break;
        }
        
        return i-k+1;
     }
         
     }
     
     return -1;
     
}