class Solution {
public:
    bool canRun(vector<int>& batteries, int n, long long mid_minutes){
        long long target_min = n * mid_minutes;

        long long sum = 0;
        for(int i = 0; i < batteries.size(); i++){
            sum += min((long long)batteries[i], mid_minutes);
        }

        if(sum >= target_min){
            return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long  total_minutes = 0;
        long long max_minutes = 0;

        for(int i = 0; i < batteries.size(); i++){
            total_minutes += batteries[i];
        }

        long long left = *min_element(batteries.begin(), batteries.end());
        long long right = total_minutes / n;
        
        while(left <= right){
            long long mid = left + (right - left)/2;

            if(canRun(batteries, n, mid)){
                max_minutes = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
    
    return max_minutes;
    }
};
