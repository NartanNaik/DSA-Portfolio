#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *insertToHead(Node *head, int data)
{
    if (head == NULL)
    {
        return new Node(data);
    }
    Node *newHead = new Node(data);
    newHead->next = head;
    return newHead;
}

Node *insertToTail(Node *head, int data)
{
    Node *temp = head;
    if (head == NULL)
    {
        return new Node(data);
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(data);
    temp->next = newNode;
    return head;
}

Node *insertToK(Node *head, int k, int data)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(data);
        }
        else
        {
            return NULL;
        }
    }

    if (k == 1)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    Node *temp = head;
    int cnt = 1;

    while (temp != NULL && cnt < k - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL)
    {
        return head;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node *insertAfterData(Node *head, int data, int value)
{
    Node *temp = head;
    while (temp != nullptr && temp->data != data)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return head;
    }

    Node *newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node *insertBeforeData(Node *head, int data, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        return head;
    }

    if (head->data == data)
    {
        newNode->next = head;
        return newNode;
    }

    Node *prev = nullptr;
    Node *temp = head;

    while (temp != nullptr && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        delete newNode;
        return head;
    }

    prev->next = newNode;
    newNode->next = temp;
    
    return head;
}

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

Node *array2LL(vector<int> &a)
{
    if (a.empty())
    {
        return nullptr;
    }

    Node *head = new Node(a[0]);
    Node *move = head;
    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i]);
        move->next = temp;
        move = temp;
    }
    return head;
}

int main()
{
    int n;
    cout << "Enter the linked List size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the ll contents:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *head = array2LL(arr);
    cout << "Old Linked List: ";
    printLL(head);
    int data;
    cout << "\nEnter the data: ";
    cin >> data;
    int value;
    cout << "\nEnter the value: ";
    cin >> value;

    // int k;
    // cout << "Enter k: ";
    // cin >> k;

    // Node *newHead = insertToHead(head, data);

    // Node *newTail = insertToTail(head, data);

    // cout << "\nNew Linked List: ";
    // printLL(newTail);

    // Node *newMid = insertToK(head, k, data);
    // cout << "\nNew Linked List: ";
    // printLL(newMid);

    // Node *newMid = insertAfterData(head, data, value);
    // cout << "\nNew Linked List: ";
    // printLL(newMid);

    Node *newMid = insertBeforeData(head, data, value);
    cout << "\nNew Linked List: ";
    printLL(newMid);

    // cout << "\nAnd the New head is: " << newHead->data;

    return 0;
}