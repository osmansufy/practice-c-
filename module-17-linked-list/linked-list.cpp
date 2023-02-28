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

void insertionAfterValue(Node *&head, int value, int key)
{
    Node *newNode = new Node();
    newNode->value = value;

    Node *temp = head;
    while (temp->value != key)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    delete temp;
}
void deleteAtTail(Node *&head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}
void deleteAtSpecificPosition(Node *&head, int position)
{
    Node *temp = head;
    int i = 1;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}
void deleteSpecificValue(Node *&head, int key)
{
    Node *temp = head;
    while (temp->next->value != key)
    {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}

Node *reversalNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *Next = current->next;
    while (true)
    {
        current->next = prev;
        prev = current;
        current = Next;
        if (current->next == NULL)
            break;
        Next = current->next;
    }
    return prev;
}
Node *reverseWithRecursive(Node *&head)
{

    // Base Call
    if (head->next == NULL)
    {
        return head;
    }

    // recursive call
    Node *newHead = reverseWithRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int findMid(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    if (head == NULL)
    {
        return -1;
    }
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->value;
}

void makeCycle(Node *&head, int position)
{

    Node *temp = head;
    Node *startNode;

    int count = 1;

    while (temp->next != NULL)
    {
        if (count == position)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}
bool detectCycle(Node *&head)
{
    if (!head || !head->next)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    bool meet = false;
    // step 1 to check is there any cycle in list
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            meet = true;
            break;
        }
    }

    return meet;
}

void removeCycle(Node *&head)
{

    Node *slow = head;
    Node *fast = head;

    // step 1 set slow=fast
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    // step 2 re initialization of fast

    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    //  step 3 set slow next to null

    slow->next = NULL;
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
         << "Choice 6: Insertion after a specific value" << endl
         << "Choice 7: Deletion at Head" << endl
         << "Choice 8: Deletion at Tail" << endl
         << "Choice 9: Deletion at a Specific Position" << endl
         << "Choice 10: Deletion by value" << endl
         << "Choice 11:Reversal Of List Non-recursive" << endl
         << "Choice 12:Find mid (with slow faster method)" << endl
         << "Choice 13:Make Cycle at desired position" << endl
         << "Choice 14:Detect cycle" << endl
         << "Choice 15:Remove cycle" << endl
         << "Choice 0:Exit" << endl;

    cout << "Next Choice: ";
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
        case 11:

            head = reversalNonRecursive(head);

            break;

        case 12:
            int midNodeValue;
            midNodeValue = findMid(head);

            cout << "Mid value of the linked list: " << midNodeValue << endl;

            break;
        case 13:
            cout << "Enter the Desired position to create cycle" << endl;
            cin >> position;
            makeCycle(head, position);
            break;
        case 14:
            if (detectCycle(head) == true)
            {
                cout << "There is a cycle" << endl;
            }
            else
            {
                cout << "There is no cycle" << endl;
            }

            break;
        case 15:
            if (detectCycle(head) == true)
            {
                removeCycle(head);
            }
            else
            {
                cout << "There is no cycle" << endl;
            }

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
