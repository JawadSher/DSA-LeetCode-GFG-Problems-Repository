class Solution {
public:
    bool reached_office(vector<int>& dist, double hour, int min_speed){
        double time = 0.0;
        int n = dist.size();
        for(int i = 0; i < n-1; i++){
            time += ceil(1.0 * (dist[i])/min_speed);
        }

        time += 1.0 * dist[n-1] / min_speed;

        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int start = 1;
        int end = 1e7;
        int result = -1;

        while(start <= end){
            int min_speed = start + (end - start)/2;

            if(reached_office(dist, hour, min_speed)){
                result = min_speed;
                end = min_speed - 1;
            }else{
                start = min_speed + 1;
            }
        }

        return result;
    }
};
