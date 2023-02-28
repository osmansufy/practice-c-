#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *current = head;
        ListNode *next;

        while (current && current->next)
        {

            next = current->next;

            if (next->val == current->val)
            {

                current = next->next;
            }
            else
            {
                current = next;
            }
        }
    }
};
