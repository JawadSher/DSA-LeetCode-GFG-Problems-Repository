class Solution {
public:

    int can_eat_all(vector<int>& piles, int mid, int h){
        int actual_hours = 0;
        for(int p : piles){
            actual_hours += p/mid;

            if(p % mid != 0){
                actual_hours++;
            }
        }
        return actual_hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        while(start < end){
            int mid = start + (end - start)/2;

            if(can_eat_all(piles, mid, h)){
                end = mid;
            }else{
                start = mid + 1;
            }
        }
        return start;
    }
};
