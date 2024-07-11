class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start = 1;
        long long end = *max_element(time.begin(), time.end()) * (long long)totalTrips;
        long long result = end;

        while(start <= end){
            long long trips = 0;
            long long mid = start + (end - start)/2;

            for(int t : time){
                trips += mid/t;
                if(trips >= totalTrips){
                    break;
                }
            }

            if(trips >= totalTrips){
                result = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return result;
    }
};
