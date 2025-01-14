#include <iostream>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\3circular linked list\0import.cpp"
using namespace std;

pair<Node*, Node*> divideCLL(Node* &tail) {
    if (tail == NULL || tail->next == tail) return make_pair(nullptr, nullptr);

    Node* mid = tail;
    Node* fast = tail->next;  

    do {
        mid = mid->next;
        fast = fast->next->next;
    } while (fast != tail && fast->next != tail);

    Node* t1 = mid;
    Node* t2 = mid->next;  

    t1->next = tail;

    while (t2->next != tail) t2 = t2->next; 
    t2->next = mid->next;

    return make_pair(t1, t2);
}

int main() {
    Node* n1 = NULL;
    Node* tail = n1;
    insertNode(tail, 14);
    insertNode(tail, 21, 14);
    insertNode(tail, 90, 21);
    insertNode(tail, 32, 90);
    insertNode(tail, 43, 32);
    insertNode(tail, 45, 43);
    printCLL(tail);

    pair<Node*, Node*> tails = divideCLL(tail);
    cout << endl;
    printCLL(tails.first);
    cout << endl;
    printCLL(tails.second);

    return 0;
}
