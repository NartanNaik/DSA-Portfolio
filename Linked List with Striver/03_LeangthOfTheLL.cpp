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
int leangthOfLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Node *head = new Node(arr[0]);
    int cnt = leangthOfLL(head);
    cout << "And the leangth od the ll is: " << cnt;
    return 0;
}