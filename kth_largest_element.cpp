#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){

    vector<int> A = {1,3};
    int k = 1;

    priority_queue<int>  q;

    for (int i = 0; i < A.size(); i++)
    {
        q.push(A[i]);
    }


     for (int i = 1; i < k; i++)
     {
        q.pop();
     }
        
        cout<<q.top();

    return 0;
}


//Quick Select Algorithm

// int partition(vector<int>& arr, int left, int right) {

//     int pivot = arr[left] ;
//     int l = left + 1 ;
//     int r = right;
//     while (l <= r) {

//         if (arr[l] < pivot && arr[r] > pivot) {
//             swap(arr[l], arr[r]);
//             l++ ;
//             r-- ;
//         }
//         if (arr[l] >= pivot) {
//             l++;
//         }
//         if (arr[r] <= pivot) {
//             r--;
//         }

//     }   
//     swap(arr[left], arr[r]);

//     // for (auto i : arr )
//     // {
//     //     cout<<i<<" ";
//     // }
    

//     return r;
// }

// int kth_Largest_Element(vector<int>& arr, int k) {

//     partition(arr,0,arr.size()-1);
//     int left = 0, right = arr.size() - 1, kth;
//     while (1) {
//         int idx = partition(arr, left, right);
//         if (idx-left == k - 1) {
//             kth = arr[idx];
//             break;
//         }
//         if (idx-left < k - 1) {
//             right = idx - 1;
//         } else {
//             left = idx + 1;
//         }
//     }
//     return kth;
 
// }

