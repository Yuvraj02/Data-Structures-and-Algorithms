 #include <iostream>
 #include <vector>
 #include <unordered_set>

 using namespace std;

int sumoflength(int arr[], int n) {
        
        unordered_set<int> s;
        
        int j = 0,length_sum = 0;
        
        //The idea is to use a flexible shrinking and expanding window
        // First increment j pointer untile we get a repeating element and add windows
        //Then increment i and shrink window upto j and add length of window
        for(int i=0 ; i<n ; i++){
             
            while(j<n && s.find(arr[j])==s.end()){
                s.insert(arr[j]);
                j++;
            }
            
            int a = j-i;
            length_sum += (a*(a+1))/2;
            s.erase(arr[i]);
        }
        return length_sum;
    }

    int main(){

    int arr[] = { 1 ,2, 3, 1,4,5 ,2 ,3, 6};
    int n = 9;
    
    cout<<sumoflength(arr,n);
    return 0;
}