#include <iostream>
using namespace std;
// insertion sort algorithm to sort an array
void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// find first element's last index in an array

int findLastIndex(int *arr, int size)
{
    int firstElementValue = arr[0];
    int firstElementIndex = 0;
    for (int i = 0; i < size; i++)
    {

        if (arr[i] == firstElementValue)
        {
            firstElementIndex = i;
        }
    }
    return firstElementIndex;
}

int main()
{
    int testCase;
    cin >> testCase;
    int removedElements = 0;

    int *outputArr = new int[testCase];
    for (int i = 0; i < testCase; i++)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        insertionSort(arr, n);

        int firstElementLastIndex = findLastIndex(arr, n);

        removedElements = n - (firstElementLastIndex + 1);

        outputArr[i] = removedElements;
    }

    for (int i = 0; i < testCase; i++)
    {
        cout << outputArr[i] << endl;
    }
    return 0;
}