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

void printLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

Node *OptimalSortLL(Node *head)
{
    // TC => O(N)
    // SC => O(1)

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *temp = head;

    Node *zeroNode = new Node(-1);
    Node *oneNode = new Node(-1);
    Node *twoNode = new Node(-1);

    Node *zero = zeroNode;
    Node *one = oneNode;
    Node *two = twoNode;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else if (temp->data == 2)
        {
            two->next = temp;
            two = temp;
        }

        temp = temp->next;
    }

    if (oneNode->next != nullptr)
    {
        zero->next = oneNode->next;
    }
    else
    {
        zero->next = twoNode->next;
    }

    one->next = twoNode->next;
    two->next = nullptr;

    Node *newNode = zeroNode->next != nullptr ? zeroNode->next : (oneNode->next != nullptr ? oneNode->next : twoNode->next);

    delete zeroNode;
    delete oneNode;
    delete twoNode;

    return newNode;
}

int main()
{
    vector<int> a = {0, 2, 1, 0, 1, 1, 0, 0, 2};
    Node *head = array2LL(a);
    Node *newNode = OptimalSortLL(head);
    cout << "Sorted LL: \n";
    printLL(head);
    return 0;
}