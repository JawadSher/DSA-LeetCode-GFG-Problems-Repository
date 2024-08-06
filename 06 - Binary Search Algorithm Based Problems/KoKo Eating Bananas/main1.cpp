class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        while(start < end){
            int mid = start + (end - start)/2;

            int actual_hours = 0;
            for(int p : piles){
                actual_hours += (p - 1) / mid + 1;
            }

            if(actual_hours > h){
                start = mid + 1;
            }else{
                end = mid;
            }
            
        }
        return start;
    }
};
