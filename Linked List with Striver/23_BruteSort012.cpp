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

Node *BruteSortLL(Node *head)
{
    // TC -> O(2N)
    // SC -> O(1)

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            cnt0++;
        }
        else if (temp->data == 1)
        {
            cnt1++;
        }
        else if (temp->data == 2)
        {
            cnt2++;
        }
        temp = temp->next;
    }

    temp = head;

    for (int i = 0; i < cnt0; i++)
    {
        temp->data = 0;
        temp = temp->next;
    }
    for (int i = 0; i < cnt1; i++)
    {
        temp->data = 1;
        temp = temp->next;
    }
    for (int i = 0; i < cnt2; i++)
    {
        temp->data = 2;
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> a = {0,2,1,0,1,1,0,0,2};
    Node *head = array2LL(a);
    Node *newNode = BruteSortLL(head);
    cout << "Sorted LL: \n";
    printLL(head);
    return 0;
}