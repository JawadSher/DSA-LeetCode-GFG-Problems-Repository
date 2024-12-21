class Solution {
  public:

    // Function to find the maximum number of meetings that can be scheduled
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size(); // Get the number of meetings
        
        // Vector to store pairs of (start time, end time) for each meeting
        vector<pair<int, int>> v;
        
        // Populate the vector with pairs of start and end times
        for(int i = 0; i < n; i++) {
            pair<int, int> p = make_pair(start[i], end[i]); // Create a pair of start and end time
            v.push_back(p); // Add the pair to the vector
        }
        
        // Sort the meetings based on their end times
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second; // Sort by the second element (end time) of the pair
        });
        
        // Initialize count of selected meetings and set the end time of the first meeting
        int count = 1; // The first meeting is always selected
        int ansEnd = v[0].second; // Set the end time of the first meeting
        
        // Iterate through the remaining meetings
        for(int i = 1; i < n; i++) {
            // If the start time of the current meeting is greater than the end time of the last selected meeting
            if(v[i].first > ansEnd) {
                count++; // Increment the count of selected meetings
                ansEnd = v[i].second; // Update the end time to the current meeting's end time
            }
        }
        
        // Return the maximum number of non-overlapping meetings
        return count;
    }
};
