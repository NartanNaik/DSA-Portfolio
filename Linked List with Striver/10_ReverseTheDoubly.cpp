#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *array2DLL(vector<int> &a)
{
    if (a.empty())
        return nullptr;
    Node *head = new Node(a[0]);
    Node *prev = head;
    for (int i = 1; i < a.size(); i++)
    {
        Node *current = new Node(a[i], nullptr, prev);
        prev->next = current;
        prev = current;
    }
    return head;
}

void printDLL(Node *head)
{
    cout << "NULL <-> ";
    while (head != nullptr)
    {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL";
}

Node *BruteReverseTheDLL(Node *head)
{
    // TC -> O(2N) ..using 2 while loops which are running through entire DLL
    // SC -> O(N) ..using stack for storing whole data

    if (head == nullptr)
    {
        return head;
    }

    if (head->next == nullptr)
    {
        return head;
    }

    stack<int> st;
    Node *current = head;
    while (current != nullptr)
    {
        st.push(current->data);
        current = current->next;
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

Node *BetterReverseTheDLL(Node *head)
{

    if (head == nullptr)
    {
        return head;
    }

    if (head->next == nullptr)
    {
        return head;
    }

    Node *current = head;
    Node *temp = nullptr;

    while (current != nullptr)
    {
        temp = current->back;
        current->back = current->next;
        current->next = temp;
        current = current->back;
    }
    if (temp != nullptr)
    {
        head = temp->back;
    }

    return head;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    Node *head = array2DLL(a);
    cout << "Before:\n";
    printDLL(head);
    // Node *finalHead = BruteReverseTheDLL(head);
    Node *finalHead = BetterReverseTheDLL(head);
    cout << "\nAfter:\n";
    printDLL(finalHead);
    return 0;
}