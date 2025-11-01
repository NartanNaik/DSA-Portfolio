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

bool PalindromeOrNot(Node *head)
{
    // TC -> O(2N)
    // SC -> O(N) due to the stack

    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }
    stack<int> st;
    Node *temp = head;
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        if (temp->data != st.top())
        {
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}

Node *reverseTheLL(Node *head)
{
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

bool optimizedPalindromeCheck(Node *head)
{
    // TC -> O(2N)
    // SC -> O(1)
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newNode = reverseTheLL(slow->next);

    Node *first = head;
    Node *second = newNode;

    while (second != nullptr)
    {
        if (first->data != second->data)
        {
            reverseTheLL(newNode);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseTheLL(newNode);
    return true;
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
    cout << "\nYour Linked list: \n";
    printLL(head);
    // if (PalindromeOrNot(head))
    // {
    //     cout << "\nThe Linked list is palindrome!";
    // }
    // else
    // {
    //     cout << "\nThe linked list is not the palindrome";
    // }
    if (optimizedPalindromeCheck(head))
    {
        cout << "\nThe Linked list is palindrome!";
    }
    else
    {
        cout << "\nThe linked list is not the palindrome";
    }
    return 0;
}