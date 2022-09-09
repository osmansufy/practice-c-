#include <iostream>
using namespace std;

int main()
{

    int examArr[4];
    int largerThen10 = 0;

    for (int i = 0; i < 4; i++)
    {
        int exam;
        cin >> exam;
        examArr[i] = exam;
        if (exam >= 10)
        {
            largerThen10++;
        }
    }

    cout << largerThen10 << endl;

    return 0;
}