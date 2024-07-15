class Solution {
public:
    long long findCost(vector<int>& nums, int mid, vector<int>& cost){
        int m = nums.size();
        
        long long total_cost = 0;

        for(int i = 0; i < m; i++){
            total_cost += (long long)abs(nums[i] - mid) * cost[i];
        }

        return total_cost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long answer = LLONG_MAX;

        int start = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());

        while(start <= end){
            int mid = start + (end - start)/2;

            long long cost1 = findCost(nums, mid, cost);
            long long cost2 = findCost(nums, mid+1, cost);

            answer = min(cost1, cost2);

            if(cost2 > cost1){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return answer == INT_MAX ? 0 : answer;   
    }
};
