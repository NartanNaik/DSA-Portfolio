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

void printDLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head = head->next;
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

Node *deleteTheFirstNode(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }
    Node *temp = head;
    head = head->next;
    if (head != nullptr)
    {
        head->back = nullptr;
    }
    temp->next = nullptr;
    delete temp;
    return head;
}

Node *deleteTheTail(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

Node *deleteTheK(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->next == nullptr)
    {
        if (k == 1)
        {
            delete head;
            return nullptr;
        }
    }

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->back = nullptr;
        }
        delete temp;
        return head;
    }

    int cnt = 1;
    Node *temp = head;

    while (temp != nullptr && cnt < k)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr)
    {
        return head;
    }

    Node *prev = temp->back;
    Node *nextNode = temp->next;

    if (prev != nullptr)
    {
        prev->next = nextNode;
    }
    if (nextNode != nullptr)
    {
        nextNode->back = prev;
    }

    temp->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node *deleteTheData(Node *head, int data)
{
    if (head == nullptr)
    {
        return head;
    }

    if (head->data == data)
    {
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->back = nullptr;
        }
        delete head;
        return nullptr;
    }

    Node *temp = head;
    while (temp != nullptr && temp->data != data)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return head;
    }

    Node *prev = temp->back;
    Node *nextNode = temp->next;

    if (prev != nullptr)
    {
        prev->next = nextNode;
    }
    if (nextNode != nullptr)
    {
        nextNode->back = prev;
    }

    delete temp;
    return head;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    Node *head = array2DLL(a);
    cout << "Before:\n";
    printDLL(head);
    // Node *newNode = deleteTheFirstNode(head);
    // Node *newNode = deleteTheTail(head);
    // int k;
    // cout << "\nEnter the k: ";
    // cin >> k;
    // Node *newNode = deleteTheK(head, k);
    int data;
    cout << "\nEnter the Data: ";
    cin >> data;
    Node *newNode = deleteTheData(head, data);
    cout << "\nAfter:\n";
    printDLL(newNode);
    return 0;
}