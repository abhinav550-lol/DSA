#include <bits/stdc++.h> 
class CircularQueue{
    int *arr;
    int front;
    int back;
    int size;

    int findEmptyLocation(int back){
        for(int i = 0; i< size; i++){
            if(arr[i] == -1){
                return i;
            }
        }
        return -1;
    }
    int findOccupiedLocation(int back){
        for(int i = 0; i< size; i++){
            if(arr[i] != -1){
                return i;
            }
        }
        return -1;
    }
    
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        for(int i = 0;i<size;i++){
            arr[i] = -1;
        }
        front = 0;
        back = 0;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if(back==size || arr[back] != -1 || back == -1){
        back = findEmptyLocation(back);
        if(back == -1)   return false;
        }
        arr[back] = value;
        back++;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
      if(back == front || front ==size || front == -1) {
          front = findOccupiedLocation(front);
          if(front == -1) return -1;
      }
        int res = arr[front];
        arr[front] = -1;
        front++;
        return res; 
    }
};