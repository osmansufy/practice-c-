#include <iostream>
using namespace std;

int main()
{
    string s;

    cin >> s;

    int n = s.length();

    int aFirstIndex = 0;
    int zLastIndex = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            aFirstIndex = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'Z')
        {
            zLastIndex = i;
            break;
        }
    }

    cout << zLastIndex - aFirstIndex + 1 << endl;

    return 0;
}
