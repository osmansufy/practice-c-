// WAP that will take n integers into an array A and m positive integers into array B. Now find the intersection (set operation) of arrays A and B.

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    int *A = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cin >> m;
    int *B = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    int *C = new int[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int k = 0; k < m; k++)
        {
            if (A[i] == B[k])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            C[j] = A[i];
            j++;
        }
    }
    for (int i = 0; i < j; i++)
    {
        cout << C[i] << " ";
    }
    return 0;
}