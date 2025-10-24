#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void printDoubly(Node *head)
{
    cout << "NULL <-> ";
    while (head != nullptr)
    {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL";
}

Node *array2DLL(vector<int> &a)
{
    if (a.empty())
    {
        return nullptr;
    }

    Node *head = new Node(a[0]);
    Node *prev = head;
    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node *insertToHead(Node *head, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        newNode->back = nullptr;
        newNode->next = nullptr;
        return newNode;
    }

    newNode->next = head;
    newNode->back = nullptr;
    head->back = nullptr;
    head = newNode;
    return head;
}

Node *insertToTail(Node *head, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        newNode->back = nullptr;
        newNode->next = nullptr;
        return newNode;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = nullptr;
    newNode->back = temp;
    return head;
}

Node *insertToK(Node *head, int k, int data)
{
    Node *newNode = new Node(data);

    if (k == 1)
    {
        newNode->next = head;
        newNode->back = nullptr;
        if (head != nullptr)
        {
            head->back = newNode;
        }
        return newNode;
    }

    Node *temp = head;
    int cnt = 1;
    while (temp != nullptr && cnt < k)
    {
        temp = temp->next;
        cnt++;
    }
    Node *prev = temp->back;
    if (prev != nullptr)
    {
        prev->next = newNode;
    }
    newNode->next = temp;
    newNode->back = prev;
    temp->back = newNode;
    return head;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    Node *head = array2DLL(a);
    cout << "Before: \n";
    printDoubly(head);
    int data;
    cout << "\nEnter the data: ";
    cin >> data;
    int k;
    cout << "\nEnter the K: ";
    cin >> k;
    // Node *newLL = insertToHead(head, data);
    // Node *newLL = insertToTail(head, data);
    Node *newLL = insertToK(head, k, data);
    cout << "\nAfter: \n";
    printDoubly(newLL);
    return 0;
}