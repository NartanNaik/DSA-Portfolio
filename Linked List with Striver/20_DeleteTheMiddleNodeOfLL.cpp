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

Node *deleteTheMiddleNode(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete (head);
        return nullptr;
    }

    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    delete (slow);
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
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Node *head = array2LL(a);
    cout << "The array before the deletion of the midddle node: \n";
    printLL(head);
    Node *newHead = deleteTheMiddleNode(head);
    cout << "The array after the deletion of the midddle node: \n";
    printLL(head);
    return 0;
}