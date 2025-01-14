#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
public:
    Node *next;
    int value;
    Node(int data)
    {
        value = data;
        next = NULL;
    }
};

void insertAthead(Node *&head, int data)
{
    Node *n2 = new Node(data); // The data is used to create a new node
    n2->next = head;           // the new node is then set to be point to the head
    head = n2;                 // the new node is now the head node  ILLUSTRATION  --> [ 5 , addOfn1 -]--> [10,-]-->NULL
}

void printLL(Node *head){
    Node* temp = head;
    while(temp!= NULL)
    {
        cout<<temp->value<<' ';
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    Node *n1 = new Node(10); // n1 is the head node
    Node *head = n1;
    printLL(head);

    insertAthead(head, 5);
    insertAthead(head,15);
    printLL(head);
    return 0;
}