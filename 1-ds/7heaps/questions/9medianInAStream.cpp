#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int signum(int a , int b){    return a == b ? 0 : (a > b) ? 1 : -1; }

void findMedianAndAddElem(int element, priority_queue<int> &maxHeap, priority_queue< int , vector<int> , greater<int>> &minHeap, int &median){
    switch (signum(maxHeap.size() , minHeap.size())){
    case 0:
        if(element > median){
            minHeap.push(element);
            median = minHeap.top();
        }else{
            maxHeap.push(element);
            median = maxHeap.top();
        }
        break;
    case 1: 
        if(element > median){
            minHeap.push(element);
        }else{
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(element);
        }
        median = (maxHeap.top() + minHeap.top()) / 2;
        break;
    case -1:
          if(element > median){
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(element);
          }else{
            maxHeap.push(element);
          }
        median = (maxHeap.top() + minHeap.top()) / 2;
    }
}

vector<int> findMedian(vector<int> &arr, int n){
    vector<int> res;
    int median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int , vector<int> , greater<int>> minHeap;
    for(int i=0;i<n;++i){
        findMedianAndAddElem(arr[i],maxHeap,minHeap,median);
        res.push_back(median);
    }
    return res;
}



int main(){
   
  return 0;
}