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

Node *BruteRemoveNthNodeFromTheLast(Node *head, int n)
{
    // TC = O(len) + O(len-N) <- length and the step(N) which we moved backword
    //         ^
    //         |-> length of the ll
    
    // SC -> O(1)

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *temp = head;
    int cnt = 0;

    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }

    if (cnt == n)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    int result = cnt - n;
    temp = head;

    while (temp != nullptr)
    {
        result--;
        if (result == 0)
        {
            break;
        }
        temp = temp->next;
    }

    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);

    return head;
}

Node *OptimalRemove(Node *head, int n)
{
    // TC -> O(len)
    // SC -> O(1)

    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    if (fast == nullptr)
    {
        return head->next;
    }

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *delNode = slow->next;
    slow->next = slow->next->next;
    delete (delNode);
    return head;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    Node *head = array2LL(a);
    cout << "Before:\n";
    printLL(head);
    int n;
    cout << "\nEnter the n: ";
    cin >> n;
    // Node *newNode = BruteRemoveNthNodeFromTheLast(head, n);
    Node *newNode = OptimalRemove(head, n);
    cout << "\nAfter:\n";
    printLL(newNode);
    return 0;
}