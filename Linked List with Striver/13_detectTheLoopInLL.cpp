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

bool detectTheLoopInLL(Node *head)
{
    // TC -> O(N)
    // SC -> O(1)

    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *head = new Node(1);
    Node *Node1 = new Node(2);
    Node *Node2 = new Node(3);
    Node *Node3 = new Node(4);
    Node *Node4 = new Node(5);
    head->next = Node1;
    Node1->next = Node2;
    Node2->next = Node3;
    Node3->next = Node4;
    Node4->next = nullptr;
    if (detectTheLoopInLL(head))
    {
        cout << "Yes there is a loop in the Linked list :(";
    }
    else
    {
        cout << "No there is no loop in the Linked list ^_^";
    }

    return 0;
}