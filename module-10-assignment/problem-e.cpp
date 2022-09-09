#include <iostream>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int n, q;
        cin >> n >> q;
        int arr[n];

        int *outputArr = new int[q];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int prefixSumArr[n];

        prefixSumArr[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefixSumArr[i] = prefixSumArr[i - 1] + arr[i];
        }
        for (int i = 0; i < q; i++)
        {
            // get query type

            int queryType;

            cin >> queryType;

            if (queryType == 1)
            {
                int index, value;
                cin >> index;

                value = arr[index];

                arr[index] = 0;

                for (int i = index; i < n; i++)
                {
                    prefixSumArr[i] = prefixSumArr[i] - value;
                }

                outputArr[i] = value;
            }
            else if (queryType == 2)
            {
                int inputIndex, inputValue;
                cin >> inputIndex >> inputValue;
                arr[inputIndex] += inputValue;
                for (int i = inputIndex; i < n; i++)
                {
                    prefixSumArr[i] = prefixSumArr[i] + inputValue;
                }
                outputArr[i] = -1;
            }
            else if (queryType == 3)
            {
                int leftIndex, rightIndex;
                cin >> leftIndex >> rightIndex;
                if (leftIndex == 0)
                {

                    outputArr[i] = prefixSumArr[rightIndex];
                }
                else
                {

                    outputArr[i] = prefixSumArr[rightIndex] - prefixSumArr[leftIndex - 1];
                }
            }
        }
        // print output array after each test case is completed and remove undefined values

        cout << "Case " << i + 1 << ":" << endl;
        for (int i = 0; i < q; i++)
        {
            if (outputArr[i] != -1)
            {
                cout << outputArr[i] << endl;
            }
        }
    }
    return 0;
}