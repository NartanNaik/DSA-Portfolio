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

Node *reverseLL(Node *head)
{
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

int helper(Node *temp)
{
    if (temp == nullptr)
    {
        return 1;
    }
    int carry = helper(temp->next);
    temp->data += carry;
    if (temp->data < 10)
    {
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node *addingOneToLL(Node *head)
{
    // TC -> O(N)
    // SC -> O(N) for recursive stack space
    int carry = helper(head);
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

void printLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
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
int main()
{
    vector<int> a = {1, 5, 9};
    Node *head = array2LL(a);
    cout << "Before adding one is: \n";
    printLL(head);
    Node *newNode = addingOneToLL(head);
    cout << "After adding one is: \n";
    printLL(newNode);
    return 0;
}