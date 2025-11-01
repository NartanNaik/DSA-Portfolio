#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

int lengthOfTheLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            int cnt = 1;
            while (fast->next != slow)
            {
                cnt++;
                fast = fast->next;
            }
            return cnt;
        }
    }
    return 0;
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
    Node4->next = head;
    int value = lengthOfTheLoop(head);
    cout << "The length of the loop is (if it's 0 that means there is no loop): " << value;
    return 0;
}