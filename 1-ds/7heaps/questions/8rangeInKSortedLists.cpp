// You are given ‘K’ lists containing non-negative integers. Each list has a size ‘N’ and is sorted in non-decreasing order. You need to find the minimum length of a range such that at least one element of each list must be included in that range.

// For example :

// If we have 3 lists as [1, 10, 11], [2, 3, 20], [5, 6, 12] then the [1, 5] is the range that includes 1 from the first list, 2,3 from the second list, and 5 from the third list i.e, this range contains at least one element from each list.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;



class info {
public:
    int val;
    int listIndex;
    int pos;
    info(int v, int li, int p) : val(v), listIndex(li), pos(p) {}
};

class customOptions {
public:
    bool operator()(info* a, info* b) {
        return a->val > b->val;
    }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    int currMax = INT_MIN;
    int smallestRange = INT_MAX;
    priority_queue<info*, vector<info*>, customOptions> pq;

    for(int i=0;i<k;i++){
        int element = a[i][0];
        pq.push(new info(element,i,0));
         currMax = max(element, currMax);
    }

    while(!pq.empty()){
        info* curr = pq.top();
        pq.pop();
        int currMin = curr -> val;
        int li = curr -> listIndex;
        int i = curr -> pos;

        int range = currMax - currMin;
        smallestRange = min(range,smallestRange); 

        if(i + 1 < a[li].size()){
            int element = a[li][i+1];
             currMax = max(element, currMax);
            pq.push(new info(element,li,i+1)); 
        }else{
            break ;
        }
    }
    return smallestRange + 1;
}




int main(){
   
  return 0;
}