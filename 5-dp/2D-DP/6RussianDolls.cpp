/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
*/

// Approach : It's a LIS(longest inc subsequnce)  Variant

class customOptions{
    public:
    bool operator()(const vector<int> &a ,const vector<int>& b){
        if(a[0] != b[0]){
        return a[0] < b[0];
        }else{
            return a[1] > b[1];
        } 
    }
};

class Solution {

    int longestSubsequence(int n, vector<int> a)  {
        if(n== 0) return 0;

        vector<int> elements;
        elements.push_back(a[0]);

        for(int  i=1 ; i<n ; i++){
            if(a[i] > elements.back()){
                elements.push_back(a[i]);
            }else{
                int index = lower_bound(elements.begin() , elements.end() , a[i]) - elements.begin();
                elements[index] = a[i];
            }
        }
        return elements.size();
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin() , envelopes.end() , customOptions());
        for(auto e: envelopes){
            cout << e[0] << ' ' << e[1] << endl;
        }
        vector<int> heights; //Apply LIS On heights of the sorted array. watch intituion on yt
        for(auto e : envelopes){
            heights.push_back(e[1]);
        }

        return longestSubsequence(heights.size() , heights);
    }
};