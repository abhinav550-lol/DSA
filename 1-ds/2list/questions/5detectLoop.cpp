#include <iostream>
#include <bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\3circular linked list\0import.cpp"
using namespace std;

// Mapping Key Value Pairs
bool detectLoopMap(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<Node* , bool> visited;
    Node *temp = head;
    while (temp != NULL)
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
// Floyd
bool detectLoopFloydCDA(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}
// beginning of the loop
Node *beginningOfLoop(Node *head)
{
    Node* fast = head;
    Node* slow = head;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow == NULL || fast == NULL || fast->next == NULL) return head;
    slow = head;
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast == slow)
        {
            return fast;
        }
    }
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 1);
    insertNode(tail, 3, 1);
    insertNode(tail, 5, 3);
    insertNode(tail, 4, 5);
    insertNode(tail, 11, 4);
    printCLL(tail);
    cout << detectLoopMap(tail) << endl;
    cout << detectLoopFloydCDA(tail) << endl;
    cout<<beginningOfLoop(tail)->data;
    return 0;
}