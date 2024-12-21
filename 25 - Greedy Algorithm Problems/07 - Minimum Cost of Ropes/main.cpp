class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // Create a min-heap (priority queue) to store the rope lengths
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Push all the rope lengths into the priority queue
        for(int i = 0; i < arr.size(); i++) pq.push(arr[i]);
        
        // Variable to store the total cost of connecting the ropes
        int totalCost = 0;
        
        // Continue combining the two smallest ropes until only one rope remains
        while(pq.size() > 1){
            // Get the two smallest ropes from the heap
            int mini_1 = pq.top();
            pq.pop();
            
            int mini_2 = pq.top();
            pq.pop();
            
            // Calculate the cost of connecting the two smallest ropes
            int total = mini_1 + mini_2;
            
            // Add this cost to the total cost
            totalCost += total;
            
            // Push the new combined rope (total length) back into the priority queue
            pq.push(total);
        }
        
        // Return the total cost of connecting all ropes
        return totalCost;
    }
};
