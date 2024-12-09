class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0; // Variable to keep track of the minimum cost so far

        // Queues to track the minimum cost for 7-day and 30-day passes
        queue<pair<int, int>> month; // Stores {day, cost} for the 30-day pass
        queue<pair<int, int>> week;  // Stores {day, cost} for the 7-day pass

        // Iterate through all the travel days
        for (int day : days) {
            // Remove outdated entries from the month queue
            // If the current day is greater than or equal to the day of the oldest entry + 30,
            // it means the 30-day pass for that day is no longer valid
            while (!month.empty() && month.front().first + 30 <= day) {
                month.pop();
            }

            // Remove outdated entries from the week queue
            // If the current day is greater than or equal to the day of the oldest entry + 7,
            // it means the 7-day pass for that day is no longer valid
            while (!week.empty() && week.front().first + 7 <= day) {
                week.pop();
            }

            // Add a new entry for the current day to the week queue
            // This represents the cost of buying a 7-day pass starting today
            week.push(make_pair(day, ans + costs[1]));

            // Add a new entry for the current day to the month queue
            // This represents the cost of buying a 30-day pass starting today
            month.push(make_pair(day, ans + costs[2]));

            // Update the minimum cost (ans) for the current day
            // Consider three options:
            // 1. Buying a 1-day pass for the current day
            // 2. Using the cheapest cost from the week queue
            // 3. Using the cheapest cost from the month queue
            ans = min(ans + costs[0], min(week.front().second, month.front().second));
        }

        // Return the total minimum cost to cover all the travel days
        return ans;
    }
};
