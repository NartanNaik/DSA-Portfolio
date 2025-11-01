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
    // TC -> O((n1+n2)*log1) it would be O(n1+n2) if we use unordered_map
    // SC -> O(n1)
    
    map<Node *, int> mpp;
    Node *temp = head1;
    while (temp != nullptr)
    {
        mpp[temp] = 1;
        temp = temp->next;
    }
    temp = head2;
    while (temp != nullptr)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return temp;
        }
        temp = temp->next;
    }

    return nullptr;
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