#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\linkedList\1singly linked list\0importLL.cpp"
using namespace std;

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
Node* reverseRest(Node* head){
    Node* curr = head;
    Node* newHead = nullptr;
    while(curr!=NULL){
        Node* save = curr->next;
        curr -> next = newHead;
        newHead = curr ;
        curr = save;
    }
    return newHead;
}
bool isPalindrome(Node* head ){
    if(head -> next == nullptr) return true;
    Node* mid = getMid(head);
    mid -> next = reverseRest(mid->next);
    Node* leftCheck = head;
    Node* rightCheck = mid->next;
    while(leftCheck!=mid->next && rightCheck != NULL){
        if(leftCheck->value != rightCheck -> value){
            mid -> next = reverseRest(mid->next);
            return false;
        }else{
            leftCheck = leftCheck-> next;
            rightCheck = rightCheck-> next;
        }
    }
    mid -> next = reverseRest(mid->next);
    return true;
}

int main()
{
    Node *n1 = new Node(1);
    Node *head = n1;
    Node *tail = n1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    printLL(head);

    cout << isPalindrome(head);
    return 0;
}
// issues with this ->
// integer overflow , O(n) space complexity
//  bool isPalindrome(Node* head){
//     if(head == nullptr ) return 0;
//     if(head->next == nullptr) return 1;
//     Node* curr = head;
//     long long int num = 0;
//     while(curr!=nullptr){
//         int digit = curr->value;
//         num = num*10 + digit ;
//         curr = curr -> next;
//     }
//     string StringNum = to_string(num);
//     int j = 0, k = StringNum.length()-1;
//     while(j<k){
//         if(StringNum[j] != StringNum[k]) return false;
//         j++;
//         k--;
//     }
//     return true;
//  }   