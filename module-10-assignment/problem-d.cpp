#include <bits/stdc++.h>
using namespace std;
// find the maximum frequency of a number in an array of integers 1 2 4
int maxFrequency(int *arr, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > max)
        {
            max = count;
        }
    }
    return max;
}

int main()
{
    int t;
    cin >> t;
    int *outputArr = new int[t];
    for (int i = 0; i < t; i++)

    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        outputArr[i] = n - maxFrequency(arr, n);
    }

    for (int i = 0; i < t; i++)
    {
        cout << outputArr[i] << endl;
    }
    return 0;
}