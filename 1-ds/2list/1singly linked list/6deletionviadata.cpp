#include <iostream>
#include<bits/stdc++.h>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\1singly linked list\0importLL.cpp"
// comment this line ^^^^ when practicing

using namespace std;
 
void deleteByValue(Node* &head, Node* &tail , int key) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->value == key) {
            if (prev == nullptr) {
                // If the node to delete is the head
                head = current->next;
                delete current;
                current = head;
                if (head == nullptr)
                    tail = nullptr; // Update tail if the list becomes empty
            } else {
                prev->next = current->next;
                if (current == tail)
                    tail = prev; // Update tail if the last node is deleted
                delete current;
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}


int main(){
    Node* n = new Node(10);
    Node* head=n;
    Node* tail=n;
    insertAtTail(tail,15);
    insertAtTail(tail,20);
    insertAtTail(tail,25);
    printLL(head);

    deleteByValue(head, tail,10);
    printLL(head);

  return 0;
}