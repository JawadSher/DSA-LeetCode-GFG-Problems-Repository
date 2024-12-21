class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        
        // Step 1: Create a vector of tuples to store job details (profit, job id, and deadline)
        vector<tuple<int, int, int>> v;
        
        // Loop through the job arrays and create tuples of (profit, job id, deadline)
        for(int i = 0; i < id.size(); i++){
            v.push_back(make_tuple(profit[i], id[i], deadline[i]));
        }
        
        // Step 2: Sort the jobs by profit in descending order
        // The job with higher profit is considered first
        sort(v.begin(), v.end(), [](tuple<int, int, int>& a, tuple<int, int, int>& b){
            return get<0>(a) > get<0>(b);  // Compare based on profit (first element of the tuple)
        });
        
        // Step 3: Find the maximum deadline to define the size of the schedule array
        int maxiDeadline = INT_MIN;
        for(int i = 0; i < deadline.size(); i++){
            maxiDeadline = max(maxiDeadline, deadline[i]);
        }
        
        // Step 4: Initialize the schedule array with -1 to represent unoccupied time slots
        // The array has size `maxiDeadline + 1` because deadlines are 1-based.
        vector<int> schedule(maxiDeadline+1, -1);
        
        // Step 5: Initialize variables to track the number of jobs selected and total profit
        int count = 0;
        int maxProfit = 0;
        
        // Step 6: Try to schedule jobs in decreasing order of their profit
        for(int i = 0; i < v.size(); i++){
            int currProfit = get<0>(v[i]);   // Profit of the current job
            int currJobId = get<1>(v[i]);    // Job id of the current job
            int currDeadline = get<2>(v[i]); // Deadline of the current job
            
            // Step 7: Try to find the latest available time slot before the job's deadline
            for(int k = currDeadline; k > 0; k--){
                // If the time slot is free (schedule[k] == -1), schedule the job there
                if(schedule[k] == -1){
                    schedule[k] = currJobId; // Assign the job id to the available slot
                    maxProfit += currProfit; // Add the profit of the job to the total profit
                    count++;                // Increment the count of scheduled jobs
                    break;                  // Break out of the loop after scheduling the job
                }
            }    
        }
        
        // Step 8: Return the count of jobs scheduled and the total profit
        return {count, maxProfit};
    }
};
