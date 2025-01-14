//Longest Arithemetic Sequence 
// Given an array arr[] of sorted and distinct positive integers. The task is to find the length of the longest arithmetic progression in a given array.

//Brute Force  tc - O(n3) sc - o(n2)
class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        if(arr.size() == 1 || arr.size()  == 2){
            return arr.size();
        }
        
        unordered_map<int , bool> present;
        for(auto e : arr){
            present[e]  = true;
        }
        int res = INT_MIN;
        int n = arr.size();
        for(int i=0 ; i<n ; i++){
            for(int j=i+1; j<n;j++){
                int firstTerm = arr[i];
                int secondTerm = arr[j];
                int count = 2;
                int commonDifference = arr[j] - arr[i];
                int flag = true;
                while(flag){
                    int nextTerm = secondTerm + commonDifference;
                    if(present[nextTerm] == true){
                        firstTerm = secondTerm;
                        secondTerm = nextTerm;
                        count++;
                    }else{
                        flag = false;
                    }
                }
                res = max(count, res);
            }
        }
        return res;
    }
};

