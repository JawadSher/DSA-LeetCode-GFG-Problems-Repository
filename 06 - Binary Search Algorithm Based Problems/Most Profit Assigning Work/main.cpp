class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m = difficulty.size();
        int n = worker.size();

        vector<pair<int, int>> pairs;

        for(int i = 0; i < m; i++){
            pairs.push_back({difficulty[i], profit[i]});
        }

        sort(pairs.begin(), pairs.end());

        for(int i = 1; i < pairs.size(); i++){
            pairs[i].second = max(pairs[i].second, pairs[i-1].second);
        }

        int totalProfit = 0;

        for(int i = 0; i < n; i++){
            int maxProfit = 0;

            int l = 0;
            int r = pairs.size() - 1;

            while(l <= r){
                int mid = l + (r - l)/2;

                if(pairs[mid].first <= worker[i]){
                    maxProfit = max(maxProfit, pairs[mid].second);
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }

            totalProfit += maxProfit;
        }

    return totalProfit;
    }
};
