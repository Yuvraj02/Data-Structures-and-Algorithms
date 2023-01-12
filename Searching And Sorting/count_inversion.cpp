#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& mainArr, int start, int end){

    int mid = start + (end-start)/2;
    int lengthOfFirstArray = mid-start+1;
    int lengthOfSecondArray = end-mid;

    vector<int> firstArray(lengthOfFirstArray);
    vector<int> secondArray(lengthOfSecondArray);

    //Start Copying into arrays
    //Copy to First Array from mainArr
    int mainArrayIndex = start;
    for (int i = 0; i < lengthOfFirstArray; i++)
    {
        firstArray[i]=mainArr[mainArrayIndex++];
    }
    //Copy to Second Array from mainArr
    mainArrayIndex = mid+1;
    for (int i = 0; i < lengthOfSecondArray; i++)
    {
        secondArray[i] = mainArr[mainArrayIndex++];
    }

    //Merge 2 sorted arrays
    int firstArrIndex=0,secondArrIndex=0;
    mainArrayIndex = start;

    int inv_count = 0;
    while (firstArrIndex<lengthOfFirstArray && secondArrIndex<lengthOfSecondArray)
    {
        if(firstArray[firstArrIndex]<=secondArray[secondArrIndex]){
            mainArr[mainArrayIndex]=firstArray[firstArrIndex];
            firstArrIndex++;
        }else{
            mainArr[mainArrayIndex] = secondArray[secondArrIndex];
            secondArrIndex++;
            inv_count += (mid + 1) - (start + firstArrIndex);
        }
        mainArrayIndex++;
    }

    while (firstArrIndex<lengthOfFirstArray)
    {
        mainArr[mainArrayIndex++] = firstArray[firstArrIndex++];
    }
    while (secondArrIndex<lengthOfSecondArray)
    {
        mainArr[mainArrayIndex++] = secondArray[secondArrIndex++];
    }

    return inv_count;

}

int mergeSort(vector<int> &A, int start, int end){

    int count = 0;
    if(start>=end){
        return count;
    }
        
    
    int mid = start + (end-start)/2;

    count += mergeSort(A,start,mid);
    count += mergeSort(A,mid+1,end);

   count +=  merge(A,start,end);

return count;
}

int main(){

    vector<int> A = {2,3,4,5,6};

    cout<<"Inversion Count is : " <<mergeSort(A,0,A.size()-1)<<endl;

    for (auto i : A)
    {
        cout<<i<<" ";
    }
    

    return 0;
}