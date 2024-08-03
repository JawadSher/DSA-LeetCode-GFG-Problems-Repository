class Solution {
public:
    int make_bouquet(int mid, vector<int>& bloomDay, int m, int k){
        int bouquet_count = 0;
        int flowers_count = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                flowers_count++;
            }else{
                flowers_count = 0;
            }

            if(flowers_count == k){
                bouquet_count++;
                flowers_count = 0;
            }
        }
        return bouquet_count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start_day = 0;
        int end_day = *max_element(bloomDay.begin(), bloomDay.end());

        int result = -1;
        while(start_day <= end_day){
            int mid = start_day + (end_day - start_day)/2;

            if(make_bouquet(mid, bloomDay, m, k) >= m){
                result = mid;
                end_day = mid - 1;
            }else{
                start_day = mid + 1;
            }
        }

    return result;
    }
};
