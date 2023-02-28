#include <bits/stdc++.h>
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// solution for singly linked list if k is less then size of linked list
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (k == 0)
            return head;

        int count = 1;

        ListNode *current = head;
        // loop until kth node
        while (count < k && current != NULL)
        {
            current = current->next;
            count++;
        }

        // If current is NULL, k is greater than
        // or equal to count of nodes in linked list.
        // Don't change the list in this case

        if (current == NULL)
        {
            return head;
        }

        // Current is now in kth Node

        ListNode *KthNode = current;

        // After this current will loop until last node

        while (current->next != NULL)
        {
            current = current->next;
        }
        // connect the next of last node to prev head
        current->next = head;

        // Create new head to (kth+1) kthNode's next

        head = KthNode->next;

        // now change next of KthNode to NULL

        KthNode->next = NULL;

        return head;
    }
};

// Solution For circular linked list where k can be  greater then size of linked list
// example head =[0,1,2],k=4
class SolutionCircular
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return NULL;

        int size = 1;
        ListNode *temp = head;
        //    loop till last node and get the size of linked list

        while (temp->next)
        {
            temp = temp->next;
            size++;
        }

        // count new loop length
        int l = size - k % size;
        // change next node of last node to
        temp->next = head;

        // loop until kth(lth) node to get new head
        for (int i = 0; i < l; i++)
        {
            temp = temp->next;
        }
        // change new head to kth node and next of kth node to null
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};