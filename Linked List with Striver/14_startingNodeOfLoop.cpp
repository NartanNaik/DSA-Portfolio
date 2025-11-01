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

Node *startingNodeOfLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }
    return nullptr;
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
    Node4->next = head;
    Node *newNode = startingNodeOfLoop(Node3);
    cout << "The first node of the loop is (if it's 0 there is no loop): " << newNode->data;
    return 0;
}