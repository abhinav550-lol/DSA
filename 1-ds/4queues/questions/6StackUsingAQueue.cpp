#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
    int capacity;
    int size = 0;

    // This function reverses the queue
    void reverseQueue() {
        if (q.empty()) return;
        int frontElement = q.front();
        q.pop();
        reverseQueue();
        q.push(frontElement);
    }

public:
    Stack(int s = 5) : capacity(s) {}

    bool push(int x) {
        if (size < capacity) {
            q.push(x);
            size++;
            return true;
        }
        return false;
    }

    bool pop() {
        if (q.empty()) return false;
        reverseQueue();
        q.pop();
        size--;
        return true;
    }

    int top() {
        if (q.empty()) return -1;
        reverseQueue();
        int ans = q.front();
        q.push(ans);
        q.pop();
        return ans;
    }

    bool empty() {
        return size == 0;
    }
};


int main(){
   Stack s(3);
   cout<<s.push(44)<<endl;
   cout<<s.top()<<endl;
   cout<<s.push(32)<<endl;
   cout<<s.push(11)<<endl;
   cout<<s.pop()<<endl;
   cout<<s.push(11)<<endl;
   cout<<s.push(11)<<endl;
   cout<<s.top(); 
  return 0;
}