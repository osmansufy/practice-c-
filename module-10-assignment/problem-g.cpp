#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int firstDigit = n / 100;
    int secondDigit = n % 10;

    if (firstDigit == secondDigit)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}