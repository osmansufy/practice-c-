// Given an array with N elements, indexed from 1 to N. Now you will be given some queries in the form I J, your task is to find the minimum value from index I to J.

// Input Format
// Input starts with an integer T (≤ 5), denoting the number of test cases.

// The first line of a case is a blank line. The next line contains two integers N (1 ≤ N ≤ 105), q (1 ≤ q ≤ 50000). The next line contains N space separated integers forming the array. There integers range in [0, 105].

// The next q lines will contain a query which is in the form I J (1 ≤ I ≤ J ≤ N).

// Output Format
// For each test case, print the case number in a single line. Then for each query you have to print a line containing the minimum value between index I and J.

// Sample Input
// 2

// 5 3
// 78 1 22 12 3
// 1 2
// 3 5
// 4 4

// 1 1
// 10
// 1 1

// Sample Output
// Case 1:
// 1
// 3
// 12
// Case 2:
// 10

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, q;
        cin >> n >> q;
        int *A = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        cout << "Case " << i + 1 << ":" << endl;
        for (int i = 0; i < q; i++)
        {
            int I, J;
            cin >> I >> J;
            int min = A[I - 1];
            for (int i = I; i < J; i++)
            {
                if (A[i] < min)
                {
                    min = A[i];
                }
            }
            cout << min << endl;
        }
    }
    return 0;
}