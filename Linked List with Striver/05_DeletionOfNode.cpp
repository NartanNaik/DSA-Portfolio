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

void traverseLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *deleteTheHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteTheTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return NULL;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *deleteTheK(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    if (head->next == nullptr)
    {
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;
    int cnt = 0;
    while (temp != NULL)
    {
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        cnt++;
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deleteTheValue(Node *head, int v)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->data == v)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *prev = head;
    Node *temp = head->next;
    while (temp != NULL && temp->data != v)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return head;
    }
    prev->next = temp->next;
    delete temp;
    return head;
}

Node *converetToLL(vector<int> &a)
{
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
    vector<int> arr = {1, 2, 3, 4};
    Node *head = converetToLL(arr);
    // Node *finalHead = deleteTheHead(head);
    // Node *finalhead2 = deleteTheTail(head);
    // int K;
    // cout << "Enter the K: ";
    // cin >> K;
    // Node *finalhead3 = deleteTheK(head, K);
    int v;
    cout << "Enter the K: ";
    cin >> v;
    Node *finalhead4 = deleteTheValue(head, v);
    traverseLL(finalhead4);
    return 0;
}