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

Node *addingOneToLL(Node *head)
{
    // TC -> O(3N)
    // SC -> O(1)
    if (head == nullptr)
    {
        return nullptr;
    }

    head = reverseLL(head);
    Node *temp = head;
    int carry = 1;
    while (temp != nullptr)
    {
        int sum = temp->data + carry;
        temp->data = sum % 10; // this helps to get the right most digit
        carry = sum / 10;      // this helps to get the carry
        if (temp->next == nullptr && carry)
        {
            temp->next = new Node(carry);
            carry = 0;
        }
        temp = temp->next;
    }
    head = reverseLL(head);
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