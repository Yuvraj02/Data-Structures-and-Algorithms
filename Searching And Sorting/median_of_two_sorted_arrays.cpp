#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if(B.size()<A.size()) return findMedianSortedArrays(B,A);
     //   if(A.size()==1 && B.size()==1) return (A[0]+B[0])/2.0;
        int n1 = A.size();
        int n2 = B.size();

        int start = 0,end=n1;
        int max_each_side = (n1+n2+1)/2;
        int cut1 = start + (end-start)/2;
        //Get only left off elements
        int cut2 = max_each_side-cut1;
        //Cut1 is for first Array and cut2 is for second array
        while(start<=end){
            int l1 = cut1==0 ? INT32_MIN : A[cut1-1];
            int l2 = cut2==0 ? INT32_MIN : B[cut2-1];
            int r1 = cut1==n1 ? INT32_MAX: A[cut1];
            int r2 = cut2==n2 ? INT32_MAX: B[cut2];

            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }else{
                    return max(l1,l2);
                }
            }else if (l1>r2){
                //Reduce elements
                end = cut1-1;
            }else{
                start = cut1+1;
            }

            cut1 = start + (end-start)/2;
            cut2 = max_each_side-cut1;

        }

    return 0.0;

    }

int main(){
    vector<int> A = {7,12,14,15};
    vector<int> B = {1,2,3,4,9,11};

   cout<<findMedianSortedArrays(A,B);

}

