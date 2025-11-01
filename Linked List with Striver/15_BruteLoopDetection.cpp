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

bool detectLoopWithUnorderdMap(Node *head)
{
    unordered_map<Node *, bool> visited;
    Node *temp = head;

    while (temp != nullptr)
    {
        if (visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
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
    Node2->next = Node3;
    Node3->next = Node4;
    Node4->next = nullptr;
    if (detectLoopWithUnorderdMap(head))
    {
        cout << "Yes there is a loop in the Linked list :(";
    }
    else
    {
        cout << "No there is no loop in the Linked list ^_^";
    }

    return 0;
}