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
int searchTheData(Node *head, int value)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == value)
        {
            return 1;
        }

        temp = temp->next;
    }
    return 0;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Node *head = new Node(arr[0]);
    int value;
    cout << "Enter the value: ";
    cin >> value;
    if (searchTheData(head, value))
    {
        cout << "Yes the value " << value << " is present in the linkedList";
    }
    else
    {
        cout << "No the value " << value << " is not present in the linkedlist";
    }
    return 0;
}