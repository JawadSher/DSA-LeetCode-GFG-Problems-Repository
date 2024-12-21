class Solution {
  public:
    // Function to find the maximum number of activities that can be selected
    int activitySelection(vector<int> &start, vector<int> &end) {
        int n = start.size(); // Get the number of activities
        
        // Step 1: Create a vector of pairs to store the start and end times of each activity
        vector<pair<int, int>> v;
        
        // Step 2: Fill the vector 'v' with pairs of (start time, end time)
        for(int i = 0; i < n; i++){
            v.push_back({start[i], end[i]});
        }
        
        // Step 3: Sort the activities based on their end time (ascending order)
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;  // Sort by the end time of the activity
        });
        
        // Step 4: Initialize variables
        int activityCount = 1; // The first activity is always selected
        int endTime = v[0].second; // Set the end time of the first activity
        
        // Step 5: Loop through the remaining activities and select those that do not overlap
        for(int i = 1; i < n; i++){
            // If the start time of the current activity is greater than the end time of the last selected activity
            if(v[i].first > endTime){
                activityCount++;  // Select the activity
                endTime = v[i].second;  // Update the end time to the end time of the current activity
            }
        }
        
        // Step 6: Return the total number of activities selected
        return activityCount;
    }
};
