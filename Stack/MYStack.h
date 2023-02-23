#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->value = val;
        next = NULL;
        prev = NULL;
    }
};
class Stack
{
    Node *head;
    Node *Top;

public:
    int sizeOfLinkedList = 0;
    Stack()
    {
        head = NULL;
        Top = NULL;
    }
    // Push
    void push(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            Top = newNode;
            sizeOfLinkedList++;

            return;
        }

        Top->next = newNode;
        newNode->prev = Top;
        Top = newNode;
        sizeOfLinkedList++;
        return;
    }
    // Pop

    int pop()
    {

        Node *delNode;
        delNode = Top;
        int chk=-1;
        // there is No element in the Stack

        if (head == NULL)
        {
            cout << "Stack Underflow";
        }
        if (Top == head) // There is only one element
        {
            head = Top = NULL;
        }
        else // There is More then one element
        {
            Top = delNode->prev;
            Top->next = NULL;
        }
        chk = delNode->value;
        delete delNode;
        sizeOfLinkedList--;
        return chk;
    }

    // isEMpty

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }

        return false;
    }
    // top

    int top()
    {
        if (Top == NULL)
        {
            cout << "Stack is UnderFlow" << endl;
            return -1;
        }
        return Top->value;
    }
    // Size

    int size()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            sizeOfLinkedList++;
        }

        return sizeOfLinkedList;
    }
};