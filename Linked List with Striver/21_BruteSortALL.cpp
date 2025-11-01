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

Node *BruteSortOfTheLL(Node *head)
{
    // TC= O(N) + O(NlogN) O(N) => O(NlogN) the sort takes this time and it's dominent so..
    // SC=O(N) beecause we are using speperate array for this

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *temp = head;
    vector<int> a;
    while (temp != nullptr)
    {
        a.push_back(temp->data);
        temp = temp->next;
    }
    sort(a.begin(), a.end());
    temp = head;
    for (int i = 0; i < a.size(); i++)
    {
        temp->data = a[i];
        temp = temp->next;
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

int main()
{
    vector<int> a = {2, 5, 1, 4, 6, 8, 8};
    Node *head = array2LL(a);
    Node *newNode = BruteSortOfTheLL(head);
    cout << "Sorted LL: \n";
    printLL(head);
    return 0;
}