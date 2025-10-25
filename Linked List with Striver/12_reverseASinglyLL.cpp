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

Node *reverseLLInBrute(Node *head)
{
    // TC -> O(2N)
    // SC -> O(N)
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    stack<int> st;
    Node *temp = head;
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    Node *temp2 = head;
    while (temp2 != nullptr && !st.empty())
    {
        temp2->data = st.top();
        st.pop();
        temp2 = temp2->next;
    }
    return head;
}

Node *reverseLLInBetter(Node *head)
{
    // TC -> O(N)
    // SC -> O(1)
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
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

Node *reverseLLInRecusion(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *newHead = reverseLLInRecusion(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    Node *head = array2LL(a);
    cout << "Before reverse:\n";
    printLL(head);
    // Node *newNode = reverseLLInBrute(head);
    // Node *newNode = reverseLLInBetter(head);
    Node *newNode = reverseLLInRecusion(head);
    cout << "\nAfter reverse:\n";
    printLL(newNode);
    return 0;
}