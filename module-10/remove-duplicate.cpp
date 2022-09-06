// WAP that will take n integers into an array A. Now remove all duplicate numbers from that array. Finally, print all elements from that array.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *A = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int *B = new int[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int k = 0; k < j; k++)
        {
            if (A[i] == B[k])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            B[j] = A[i];
            j++;
        }
    }
    for (int i = 0; i < j; i++)
    {
        cout << B[i] << " ";
    }
    return 0;
}