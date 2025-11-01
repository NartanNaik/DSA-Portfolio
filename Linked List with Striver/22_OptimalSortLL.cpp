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

Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    return slow;
}

Node *mergeTwoList(Node *l1, Node *l2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->data < l2->data)
        {
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
    }
    if (l1)
    {
        temp->next = l1;
    }
    else
    {
        temp->next = l2;
    }
    return dummyNode->next;
}

Node *OptimalSortOfTheLL(Node *head)
{
    // TC = O(NlogN)
    // SC = O(1)
    
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *middle = findMiddle(head);
    Node *right = middle->next;
    middle->next = nullptr;
    Node *left = head;
    left = OptimalSortOfTheLL(left);
    right = OptimalSortOfTheLL(right);
    return mergeTwoList(left, right);
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

int main()
{
    vector<int> a = {2, 5, 1, 4, 6, 8, 8};
    Node *head = array2LL(a);
    Node *newNode = OptimalSortOfTheLL(head);
    cout << "Sorted LL: \n";
    printLL(head);
    return 0;
}