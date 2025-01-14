#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
// this is not made for 1 based indexing, its assume the user knows 1 is 0, or it means the user knows about 0 based indexing

 class NQueues{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;
    public:
    NQueues(int k,int s){
        arr = new int[s];
        next = new int[s];
        front = new int[k];
        rear = new int[k];
        for(int i=0;i<s;i++){
            next[i] = i+1;
        }
        freespot = 0;
        next[s-1] = -1;
        for(int i=0;i<k;i++){
            front[i] = -1;
            rear[i] = -1;
        }
    }

    bool enqueue(int n,int x){
        if(freespot==-1) return false;
        int index = freespot;
        freespot = next[index];
        if(front[n]==-1){
            front[n] = index;
        }else{
            next[rear[n]] = index;
        }
            next[index] = -1;
            rear[n] = index;
            arr[index] =x;
            return true;
    }

    int dequeue(int n){
        if(front[n] == -1) return -1;
        int index = front[n];
        if(front[n] == rear[n]){
            front[n] = rear[n] = -1;
        }else{
            front[n] = next[index];
        }
        next[index] = freespot;
        freespot = index;
        int ans = arr[index];
        return ans;
    }
 };

int main(){
   NQueues nq(3,6);
   cout<<nq.enqueue(0,1);
   cout<<nq.enqueue(0,2);
   cout<<nq.enqueue(1,3);
   cout<<nq.enqueue(1,4);
   cout<<nq.enqueue(2,5);
   cout<<nq.enqueue(2,6);

   cout<<nq.dequeue(1);
   cout<<nq.dequeue(1);
   cout<<nq.dequeue(1); 
  return 0;
}