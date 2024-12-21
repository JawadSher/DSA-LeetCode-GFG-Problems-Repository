class Solution {
public:
    // Function to find the order of meetings that can be scheduled
    // without overlapping, maximizing the number of meetings.
    vector<int> maxMeetings(int n, vector<int> &S, vector<int> &F) {
        vector<int> ans; // To store the result (order of meetings that can be scheduled)
        
        // Vector to store pairs of (start time, end time) with their original index
        vector<pair<pair<int, int>, int>> v;
        
        // Populate the vector with pairs of start and end times along with the meeting index
        for (int i = 0; i < n; i++) {
            v.push_back({{S[i], F[i]}, i + 1}); // Store the start time, end time, and meeting index (1-based)
        }
        
        // Sort the vector of meetings:
        // 1. First by end time (ascending).
        // 2. If two meetings have the same end time, sort by start time (ascending).
        sort(v.begin(), v.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
            if (a.first.second == b.first.second) 
                return a.first.first < b.first.first; // Sort by start time if end times are equal
            return a.first.second < b.first.second; // Otherwise, sort by end time
        });
        
        // Select the first meeting (greedy choice)
        ans.push_back(v[0].second); // Add the index of the first meeting to the result
        int endAns = v[0].first.second; // Store the end time of the first selected meeting
        
        // Iterate through the remaining meetings to find non-overlapping meetings
        for (int i = 1; i < n; i++) {
            // Check if the start time of the current meeting is greater than
            // the end time of the last selected meeting
            if (v[i].first.first > endAns) {
                ans.push_back(v[i].second); // Add the meeting index to the result
                endAns = v[i].first.second; // Update the end time to the current meeting's end time
            }
        }
        
        // Sort the result to return the meeting indices in ascending order
        sort(ans.begin(), ans.end());
        
        return ans; // Return the order of meeting indices that can be scheduled
    }
};
