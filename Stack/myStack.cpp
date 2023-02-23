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
    int sizeOfLinkedList = 0;

public:
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

    int Pop()
    {

        Node *deleteNode = Top;
        if (head == NULL)
        {

            cout << "Stack is UnderFlow" << endl;
            return -1;
        }
        if (head == Top)
        {
            head = Top = NULL;
        }
        else
        {
            Top = deleteNode->prev;
            Top->next = NULL;
        }
        delete deleteNode;
        sizeOfLinkedList--;
        return deleteNode->value;
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