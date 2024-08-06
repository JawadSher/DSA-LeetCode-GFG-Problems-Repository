class Solution {
public:
    bool possible_to_place(int midF, vector<int>& position, int m){
        int p_previous = position[0];
        int c_balls = 1;

        for(int i = 1; i < position.size(); i++){
            int p_current = position[i];

            if(p_current - p_previous >= midF){
                c_balls++;
                p_previous = p_current;
            }

            if(c_balls == m){
                break;
            }
        }

        return c_balls == m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();

        int minF = 1;
        int maxF = position[n-1] - position[0];

        int result = -1;
        while(minF <= maxF){
            int midF = minF + (maxF - minF)/2;

            if(possible_to_place(midF, position, m)){
                result = midF;
                minF = midF + 1;
            }else{
                maxF = midF - 1;
            }
        }
    return result;
    }
};
