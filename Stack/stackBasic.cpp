#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Stack
{

    Node *head;
    Node *top;

public:
    // PUSH
    void push(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            top = newNode;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
    }
    // POP

    int pop()
    {

        Node *delNode;
        delNode = top;
        int chk=1;
        // there is No element in the Stack

        if (head == NULL)
        {
            cout << "Stack Underflow";
        }
        if (top = head) // There is only one element
        {
            head = top = NULL;
        }
        else // There is More then one element
        {
            top = delNode->prev;
            top->next = NULL;
        }
        chk = delNode->value;
        delete delNode;
        return chk;
    }
};
