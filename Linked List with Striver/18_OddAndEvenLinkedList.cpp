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
    cout << "NULL";
}

Node *bruteOddAndEvenLL(Node *head)
{
    // TC = O(2N)
    // SC = O(N)

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    vector<int> odd, even;
    Node *temp = head;
    int index = 1;

    while (temp != nullptr)
    {
        if (index % 2 == 1)
        {
            odd.push_back(temp->data);
        }
        else
        {
            even.push_back(temp->data);
        }
        temp = temp->next;
        index++;
    }

    odd.insert(odd.end(), even.begin(), even.end());
    temp = head;
    int i = 0;
    while (temp != nullptr)
    {
        temp->data = odd[i++];
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    Node *head = array2LL(a);
    cout << "Before: \n";
    printLL(head);
    Node *newNode = bruteOddAndEvenLL(head);
    cout << "\nAfter: \n";
    printLL(newNode);
    return 0;
}