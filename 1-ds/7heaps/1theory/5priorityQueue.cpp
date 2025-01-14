#include <iostream>
#include <queue>
using namespace std;
 
int main(){
  priority_queue<int> maxHeap;
  priority_queue<int , vector<int> , greater<int>> minHeap;
  maxHeap.push(5);
  maxHeap.push(2);
  maxHeap.push(3);
  maxHEap.size();
  maxHeap.pop();
  cout<< maxHeap.empty();
  return 0;
}