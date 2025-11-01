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
    cout << "NULL\n";
}

Node *interSectionNode(Node *head1, Node *head2)
{
    // TC -> O(N1+N2)
    // SC -> O(1)

    if (head1 == nullptr || head2 == nullptr)
    {
        return nullptr;
    }

    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (temp1 == temp2)
        {
            return temp1;
        }

        if (temp1 == nullptr)
        {
            temp1 = head2;
        }

        if (temp2 == nullptr)
        {
            temp2 = head1;
        }
    }
    return temp1;
}

int main()
{
    Node *head = new Node(1);
    Node *Node1 = new Node(2);
    Node *Node2 = new Node(1);
    Node *Node3 = new Node(4);
    Node *Node4 = new Node(5);
    head->next = Node1;
    Node1->next = Node2;
    Node2->next = Node4;
    Node3->next = Node1;
    Node *newNode = interSectionNode(head, Node3);
    cout << "Intersection is: " << newNode->data;
    return 0;
}