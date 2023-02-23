#include <iostream>
using namespace std;

class DoubleNode
{
public:
    int value;
    DoubleNode *next;
    DoubleNode *prev;
};

void insertAtHead(DoubleNode *&head, int value)
{
    DoubleNode *newNode = new DoubleNode();
    newNode->value = value;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}

void insertAtTail(DoubleNode *&head, int value)
{
    DoubleNode *newNode = new DoubleNode();
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    DoubleNode *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// insert node at a specific position

void insertAtSpecificPosition(DoubleNode *&head, int postion, int value)
{
    DoubleNode *newNode = new DoubleNode();
    newNode->value = value;

    DoubleNode *temp = head;
    int i = 1;
    while (i < postion - 1)
    {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next->prev = newNode;
}

int searchSpecificValue(DoubleNode *&head, int key)
{
    int count = 1;
    DoubleNode *temp = head;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}

void deleteAtHead(DoubleNode *&head)
{
    DoubleNode *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void deleteAtTail(DoubleNode *&head)
{
    DoubleNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}

void deleteAtSpecificPosition(DoubleNode *&head, int position)
{
    DoubleNode *temp = head;
    int i = 1;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    DoubleNode *temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next->prev = temp;
    delete temp2;
}

void printList(DoubleNode *head)
{
    DoubleNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
// print list in reverse order

void printListReverse(DoubleNode *head)
{
    DoubleNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->prev;
    }
    cout << endl;
}
// count the number of nodes in the list

int countNodes(DoubleNode *head)
{
    int count = 0;
    DoubleNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// find Mid of linked list

int findMid(DoubleNode *&head)
{
    // Case 1:head is empty

    if (head == NULL)
    {
        return -1;
    }

    DoubleNode *slow = head;
    DoubleNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->value;
}
int main()
{

    DoubleNode *head = NULL;

    int value, choice, position;
    cout << "Choice 1:Insertion at Head" << endl
         << "Choice 2:Insertion at tail" << endl
         << "Choice 3:Insertion at specific position" << endl
         << "Choice 4:Search a specific value" << endl
         << "Choice 5:Search duplicate value" << endl
         << "Choice 6: Insertion after a specific value" << endl
         << "Choice 7: Deletion at Head" << endl
         << "Choice 8: Deletion at Tail" << endl
         << "Choice 9: Deletion at a Specific Position" << endl
         << "Choice 10: Deletion by value" << endl
         << "Choice 11:Reversal Of List Non-recursive" << endl
         << "Choice 12:Finding The Mid (Slow-fast pointer method)" << endl
         << "Choice 0:Exit" << endl;

    cout << "Next Choice: " << endl;
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value: " << endl;
            cin >> value;
            insertAtHead(head, value);
            printList(head);
            break;
        case 2:
            cout << "Enter the value: " << endl;
            cin >> value;
            insertAtTail(head, value);
            printList(head);
            break;
        case 3:
            cout << "Enter the position: " << endl;
            cin >> position;
            cout << "Enter the value: " << endl;
            cin >> value;
            insertAtSpecificPosition(head, position, value);
            printList(head);
            break;
        case 4:
            cout << "Enter the value: " << endl;
            cin >> value;
            cout << "The value is at position: " << searchSpecificValue(head, value) << endl;
            break;
        case 5:
            cout << "Delete at Head " << endl;
            deleteAtHead(head);
            printList(head);
            break;
        case 6:
            cout << "Delete at Tail " << endl;
            deleteAtTail(head);
            printList(head);
            break;
        case 7:
        {
            cout << "Enter the position: " << endl;
            cin >> position;
            deleteAtSpecificPosition(head, position);
            printList(head);
            break;
        }
        case 12:
        {
            int mid = findMid(head);
            if (mid == -1)
            {
                cout << "The LL is empty" << endl;
            }
            else
            {
                cout << "Mid value is " << mid << endl;
            }

            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
            break;
        }
        }
        cout << "Next Choice: " << endl;
        cin >> choice;
    }
    cout << "Linked list: ";

    printList(head);
    cout << "Length of the Linked List :" << countNodes(head) << endl;
}