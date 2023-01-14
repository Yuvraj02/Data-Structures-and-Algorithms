#include <iostream>

using namespace std;

long long int merge(long long A[], long long int start, long long int end)
{

    long long int mid = start + (end - start) / 2;
    long long int len1 = mid - start + 1;
    long long int len2 = end - mid;

    long long int *first = new long long int[len1];
    long long int *second = new long long int[len2];

    // Copy elements to respective arrays

    long long int mainArrayIndex = start;
    // Copy to first
    for (long long int i = 0; i < len1; i++)
    {
        first[i] = A[mainArrayIndex];
        mainArrayIndex++;
    }

    mainArrayIndex = mid + 1;

    for (long long int i = 0; i < len2; i++)
    {
        second[i] = A[mainArrayIndex];
        mainArrayIndex++;
    }

    // Merge two sorted Arrays
    long long int i = 0, j = 0, k = start;
    long long int count = 0;
    while (i < len1 && j < len2)
    {
        if (first[i] <= second[j])
        {
            A[k] = first[i];
            i++;
        }
        else
        {
            A[k] = second[j];
            j++;
            count += (mid + 1) - (start + i);
        }
        k++;
    }

    // Copy rest of the elements first array if left
    while (i < len1)
    {
        A[k] = first[i];
        k++;
        i++;
    }
    // Copy rest of the elements from second array if left

    while (j < len2)
    {
        A[k] = second[j];
        k++;
        j++;
    }

    return count;

    delete[] first;
    delete[] second;
}

long long int mergeSort(long long arr[], long long int start, long long int end)
{

    // int start = 0,end=N-1;
    long long int count = 0;
    if (start >= end)
    {
        return count;
    }

    long long int mid = start + (end - start) / 2;

    count += mergeSort(arr, start, mid);
    count += mergeSort(arr, mid + 1, end);

    count += merge(arr, start, end);

    return count;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return mergeSort(arr, 0, N - 1);
}

int main()
{

    long long int arr[] = {2, 4, 1, 3, 5};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << inversionCount(arr, N);
    return 0;
}