class Solution {
public:
    int lowerBound(int start, int end, vector<int>& potions, int min_potion){
        int answer = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(potions[mid] >= min_potion){
                answer = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return answer;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        int n = spells.size();

        int max_potion = potions[m - 1];
        vector <int> answer;
        for(int i = 0; i < n; i++){
            int spell = spells[i];
            long long min_potion = ceil((1.0 * success)/spell);

            if(min_potion > max_potion){
                answer.push_back(0);
                continue;
            }

            int index = lowerBound(0, m-1, potions, min_potion);
            int count = m - index;
            answer.push_back(count);
        }
        return answer;
    }
};
