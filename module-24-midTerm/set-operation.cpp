#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{

    // loop through nums1 and insert to set
    set<int> myset1;
    set<int> myset2;
    for (int i = 0; i < nums1.size(); i++)
    {
        myset1.insert(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        myset2.insert(nums2[i]);
    }
    vector<int> result;
    set<int>::iterator it1 = myset1.begin();
    set<int>::iterator it2 = myset2.begin();

    while (it1 != myset1.end() && it2 != myset2.end())
    {
        if (*it1 == *it2)
        {
            result.push_back(*it1);
            it1++;
            it2++;
        }
        else if (*it1 < *it2)
        {
            it1++;
        }
        else
        {
            it2++;
        }
    }

    return result;
}
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{

    // loop through nums1 and insert to set
    set<int> myset1;
    set<int> myset2;
    for (int i = 0; i < nums1.size(); i++)
    {
        myset1.insert(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        myset2.insert(nums2[i]);
    }
    vector<int> result;
    set<int>::iterator it1 = myset1.begin();
    set<int>::iterator it2 = myset2.begin();

    while (it1 != myset1.end() && it2 != myset2.end())
    {
        if (*it1 == *it2)
        {
            result.push_back(*it1);
            it1++;
            it2++;
        }
        else
        {
            if (*it1 < *it2)
            {
                it1++;
            }
            else
            {
                it2++;
            }
        }
    }

    return result;
}
