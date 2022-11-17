#include <iostream>
#include <vector>
using namespace std;


void merge(int a[], int start, int end){

    int mid = (start+end)/2;

    int length1 = mid-start+1;
    int length2 = end-mid;

    int  *first = new int[length1];
    int *second = new int[length2];

    //Copy values till start to end

    int mainArrayIndex = start;
    for (int i = 0; i < length1; i++)
    {
        first[i] = a[mainArrayIndex++];
    }
     
     mainArrayIndex = mid+1;
      for (int i = 0; i < length2; i++)
    {
        second[i] = a[mainArrayIndex++];
    }


    int index1 = 0,index2 = 0;
    mainArrayIndex = start; //k is Main array index

    //if length of the arrays is equal
    // Line 35 - 54 is code to merge 2 sorted arrays
    while (index1<length1 && index2<length2)
    {
        if(first[index1] < second[index2]){
            a[mainArrayIndex++] = first[index1++];
        }else{
            a[mainArrayIndex++] = second[index2++];
        }
    }
    
    //If length of the arrays are not equal, i,e remaining elements in the array
    while (index1 < length1)
    {
         a[mainArrayIndex++] = first[index1++];
    }

    while (index2 < length2)
    {
        a[mainArrayIndex++] = second[index2++];
    }
    
    //Make sure to delete extra array created
    delete []first;
    delete []second;

}

void mergeSort(int a[], int start, int end){

        int mid = (start+end)/2;
        

        if(start>=end){
            return ;
        }
        //Continuous break in left side
        mergeSort(a,start,mid);
        //Conitinuous break in right side
        mergeSort(a,mid+1,end);

        //When the array is broken, merge the arrays
        merge(a,start,end);

}


int main(){

        int a[] = {3,7,8,6,2,4,1};
        
        mergeSort(a,0,6);

        for (auto i : a)
        {
            cout<<i<<" ";
        }
        
        

    return 0;
}