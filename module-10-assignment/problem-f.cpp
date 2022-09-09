#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int different = 0;

    if (a != b && a != c && b != c)
    {
        different = 3;
    }
    else if (a == b && a == c && b == c)
    {
        different = 1;
    }
    else
    {
        different = 2;
    }

    cout << different << endl;

    return 0;
}