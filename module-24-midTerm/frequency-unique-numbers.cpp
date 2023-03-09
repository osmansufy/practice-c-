// WAP that will take n integers into an array. Now find out the number of occurrences for each of the unique numbers. Each line of the output will be a unique number that exists in the array and its frequency. You can print them in any order.

#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, int> frequencyMap;

// void countUniqueNumber(vector<int> &arr)
// {

//     for (int i = 0; i < arr.size(); i++)
//     {
//         int val = arr.at(i);
//         frequencyMap[val] = frequencyMap[val] + 1;
//     }

//     // create iterator
//     map<int, int>::iterator iter;
//     cout << "Frequency of the unique numbers " << endl;
//     for (iter = frequencyMap.begin(); iter != frequencyMap.end(); iter++)
//     {
//         cout << (*iter).first << " " << (*iter).second << endl;
//     }
// }
bool uniqueOccurrences(vector<int> &arr)
{
    map<int, int> frequencyMap;
    for (int i = 0; i < arr.size(); i++)
    {
        int val = arr.at(i);
        frequencyMap[val] = frequencyMap[val] + 1;
    }
    for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it)
    {
        auto nextIt = it;
        ++nextIt;
        while (nextIt != frequencyMap.end())
        {
            if (it->second == nextIt->second)
            {
                return true;
            }
            ++nextIt;
        }
    }
    return frequencyMap.size() == arr.size();
}
int main()
{
    int size;
    vector<int> uniqueNumbers;
    cout << "Enter the size of your unique number" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int item;
        cout << "Enter the number" << endl;
        cin >> item;
        uniqueNumbers.push_back(item);
    }

    uniqueOccurrences(uniqueNumbers);
    return 0;
}
