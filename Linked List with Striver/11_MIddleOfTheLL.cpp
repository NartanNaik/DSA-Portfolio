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

int middleOfTheLL(Node *head)
{
    // TC => O(N+N/2)
    // SC => O(1)

    if (head == nullptr)
    {
        return -1;
    }

    Node *temp = head;
    int cnt = 0;

    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }

    int middle = (cnt / 2);
    temp = head;
    for (int i = 0; i < middle; i++)
    {
        temp = temp->next;
    }

    return temp->data;
}

Node *betterMiddleOfTheLL(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    vector<int> a = {1, 2, 8, 9, 5, 6};
    Node *head = array2LL(a);
    cout << "The linked list: \n";
    printLL(head);
    // int ans = middleOfTheLL(head);
    Node* ans = betterMiddleOfTheLL(head);
    cout << "\nMiddle of the ll is: " << ans->data;
    return 0;
}