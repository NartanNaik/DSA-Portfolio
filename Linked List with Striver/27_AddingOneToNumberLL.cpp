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

void printLL(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    while (head != nullptr)
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
    Node *mover = head;
    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *reverseTheLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *current = head;
    Node *prev = nullptr;
    while (current != nullptr)
    {
        Node *temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}

int getCarry(Node *temp)
{
    if (temp == nullptr)
    {
        return 1;
    }
    int carry = getCarry(temp->next);
    temp->data += carry;
    if (temp->data < 10)
    {
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node *addOne(Node *head)
{
    int carry = getCarry(head);
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

int main()
{
    vector<int> a = {9, 8, 9};
    Node *head = array2LL(a);
    cout << "LL before adding 1: \n";
    printLL(head);
    Node *newHead = addOne(head);
    cout << "\nLL after adding 1: \n";
    printLL(newHead);
    return 0;
}