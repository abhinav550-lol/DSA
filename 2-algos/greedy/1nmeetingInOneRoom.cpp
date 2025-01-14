/*
You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/


class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool compare(pair<int ,int> a , pair<int , int> b){
        return a.second < b.second;
    }
    
    int maxMeetings(int n, int start[], int end[]) {
       vector<pair<int ,int>> timings;
       for(int i=0 ; i<n ;i++){
           timings.push_back({start[i] , end[i]});
       }
       sort(timings.begin() , timings.end() , compare);
       int count= 1;
       int lastMeetingEndTime = timings[0].second;
       
       for(int i=1 ; i<n ; i++){
           if(timings[i].first > lastMeetingEndTime){
               lastMeetingEndTime = timings[i].second;
               count++;
           }
       }
    return count;
    }
};
