#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
};

void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node();
    newNode->value = value;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// insert node at a specific position

void insertAtSpecificPosition(Node *&head, int postion, int value)
{
    Node *newNode = new Node();
    newNode->value = value;

    Node *temp = head;
    int i = 1;
    while (i < postion - 1)
    {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int searchSpecificValue(Node *&head, int key)
{
    int count = 1;
    Node *temp = head;

    while (temp->value != key)
    {
        // if node is null
        if (temp == NULL)
        {
            return -1;
        }
        temp = temp->next;
        count++;
    }
    return count;
}
int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    if (head == NULL)
    {
        return count;
    }
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void searchDuplicateValue(Node *&head, int key)
{
    int size;
    size = countLength(head);
    int position[size + 1], k = 1, count = 1, flag = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            position[k] = count;
            k++;
            flag = 1;
        }

        count++;
        temp = temp->next;
    }
    if (flag == 0)
        cout << "The Searched Value not found" << endl;
    else
    {
        position[0] = k;
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
                cout << ",";
        }
    }
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    int value, choice, position;

    cout << "Choice 1:Insertion at Head" << endl
         << "Choice 2:Insertion at tail" << endl
         << "Choice 3:Insertion at specific position" << endl
         << "Choice 4:Search a specific value" << endl
         << "Choice 5:Search duplicate value" << endl
         << "Choice 0:Exit" << endl;

    cin >> choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head, value);
            break;

        case 2:
            cout << "Enter the value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter the Desired postion: " << endl;
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insertAtSpecificPosition(head, position, value);
            break;
        case 4:

            cout << "Enter the value: ";
            cin >> value;
            position = searchSpecificValue(head, value);
            if (position != -1)
            {
                cout << "The number is at postion: " << position << endl;
            }
            else
            {
                cout << "The number is not found in linked list " << endl;
            }
            break;
        case 5:

            cout << "Enter the value: ";
            cin >> value;
            searchDuplicateValue(head, value);
            break;

        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    cout << "Linked list: ";

    display(head);
    cout << "Length of the Linked List :" << countLength(head) << endl;
}
